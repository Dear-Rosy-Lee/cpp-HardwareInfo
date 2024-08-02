#if defined(_WIN32) || defined(_WIN64)
#include "utils/WindowsDeviceInfo.h"
#include <dxgi.h>
#include <dxgi1_2.h>
#include <d3d11.h>
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")


WindowsDeviceInfo::WindowsDeviceInfo() {
    if (InitializeCOM()) {
        ConnectToWMI();
    }
}

WindowsDeviceInfo::~WindowsDeviceInfo() {
    DisconnectFromWMI();
    UninitializeCOM();
}

bool WindowsDeviceInfo::InitializeCOM() {
    HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        return false;
    }
    hres = CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT,
                                RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
    return SUCCEEDED(hres);
}

void WindowsDeviceInfo::UninitializeCOM() {
    CoUninitialize();
}

bool WindowsDeviceInfo::ConnectToWMI() {
    HRESULT hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER,
                                    IID_IWbemLocator, reinterpret_cast<void**>(&pLocator));
    if (FAILED(hres)) {
        return false;
    }
    hres = pLocator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), NULL, NULL, 0, NULL, 0, 0, &pServices);
    return SUCCEEDED(hres);
}

void WindowsDeviceInfo::DisconnectFromWMI() {
    if (pServices) {
        pServices->Release();
    }
    if (pLocator) {
        pLocator->Release();
    }
}

std::string WindowsDeviceInfo::GetCpuId() {
    return QueryWMI(L"SELECT ProcessorId FROM Win32_Processor", L"ProcessorId");
}

std::string WindowsDeviceInfo::GetCpuName() {
    return QueryWMI(L"SELECT Name FROM Win32_Processor", L"Name");
}

std::string WindowsDeviceInfo::GetDiskSerialNumber() {
    return QueryWMI(L"SELECT SerialNumber FROM Win32_DiskDrive", L"SerialNumber");
}

std::vector<std::string> WindowsDeviceInfo::GetDiskPartitions() {
    return QueryWMIMultiple(L"SELECT Name FROM Win32_DiskPartition", L"Name");
}

std::vector<std::string> WindowsDeviceInfo::GetDiskSizes() {
    return QueryWMIMultiple(L"SELECT Size FROM Win32_DiskDrive", L"Size");
}

std::string WindowsDeviceInfo::GetGPUName() {
    IDXGIFactory* pFactory = NULL;
    CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

    if (!pFactory) {
        return "Failed to create DXGI Factory";
    }

    IDXGIAdapter* pAdapter = NULL;
    std::string gpuName = "Unknown";
    if (SUCCEEDED(pFactory->EnumAdapters(0, &pAdapter))) {
        DXGI_ADAPTER_DESC desc;
        if (SUCCEEDED(pAdapter->GetDesc(&desc))) {
            std::wstring wstrDesc(desc.Description);
            gpuName = std::string(wstrDesc.begin(), wstrDesc.end());
        }
        pAdapter->Release();
    }

    pFactory->Release();
    return gpuName;
}


std::string WindowsDeviceInfo::GetGPUSerialNumber() {
    // 注意：通常情况下，WMI 不直接提供 GPU 序列号。这个查询可能需要厂商特定的扩展。
    return QueryWMI(L"SELECT Tag FROM Win32_VideoController", L"Tag");
}

std::string WindowsDeviceInfo::GetMACAddress() {
    return QueryWMI(L"SELECT MACAddress FROM Win32_NetworkAdapter WHERE MACAddress IS NOT NULL", L"MACAddress");
}

std::string WindowsDeviceInfo::GetOperatingSystem() {
    // return QueryWMI(L"SELECT Caption FROM Win32_OperatingSystem", L"Caption");
    #if defined(_WIN32)||defined(_WIN64)
    return "Windows";
    #endif
}

std::string WindowsDeviceInfo::GetMemorySize() {
    return QueryWMI(L"SELECT Capacity FROM Win32_PhysicalMemory", L"Capacity");
}

std::string WindowsDeviceInfo::GetMemoryName() {
    return QueryWMI(L"SELECT PartNumber FROM Win32_PhysicalMemory", L"PartNumber");
}

std::string WindowsDeviceInfo::GetMainboard() {
    return QueryWMI(L"SELECT Product FROM Win32_BaseBoard", L"Product");
}

std::string WindowsDeviceInfo::QueryWMI(const std::wstring& query, const std::wstring& property) {
    // 查询处理器ID
    IEnumWbemClassObject* pEnumerator = NULL;
    HRESULT hres = pServices->ExecQuery(
        bstr_t("WQL"), 
        _bstr_t(query.c_str()).GetBSTR(), // 正确转换为BSTR
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        NULL, 
        &pEnumerator);

    if (FAILED(hres)) {
        return "Query Failed";
    }

    IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;
    std::string result = "Unknown";
    if (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if (uReturn != 0) {
            VARIANT vtProp;
            hr = pclsObj->Get(_bstr_t(property.c_str()), 0, &vtProp, 0, 0);
            if (SUCCEEDED(hr) && vtProp.vt == VT_BSTR && vtProp.bstrVal) {
                result = _bstr_t(vtProp.bstrVal);
                VariantClear(&vtProp);
            }
            pclsObj->Release();
        }
        pEnumerator->Release();
    }
    return result;
}

std::vector<std::string> WindowsDeviceInfo::QueryWMIMultiple(const std::wstring& query, const std::wstring& property) {
    std::vector<std::string> results;

    IEnumWbemClassObject* pEnumerator = NULL;
    HRESULT hres = pServices->ExecQuery(
        bstr_t("WQL"), 
        _bstr_t(query.c_str()).GetBSTR(), // 正确转换为 BSTR
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        NULL, 
        &pEnumerator);

    if (FAILED(hres)) {
        results.push_back("Query Failed: " + std::to_string(hres));
        return results;
    }

    IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if (0 == uReturn) {
            break;
        }

        VARIANT vtProp;
        hr = pclsObj->Get(_bstr_t(property.c_str()), 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            if (vtProp.vt == VT_BSTR && vtProp.bstrVal != NULL) {
                results.push_back(static_cast<const char*>(_bstr_t(vtProp.bstrVal))); // 正确转换并添加到结果中
            } else {
                results.push_back("Unknown or Invalid Property Value");
            }
        } else {
            results.push_back("Failed to get property: " + std::to_string(hr));
        }
        VariantClear(&vtProp);
        if (pclsObj) pclsObj->Release();
    }
    if (pEnumerator) pEnumerator->Release();

    return results;
}

nlohmann::json WindowsDeviceInfo::GetAllDeviceInfoAsJson() {
    nlohmann::json deviceInfo;

    // 收集所有信息
    deviceInfo["CPU ID"] = GetCpuId();
    deviceInfo["CPU Name"] = GetCpuName();
    deviceInfo["Disk Serial Number"] = GetDiskSerialNumber();
    deviceInfo["GPU Name"] = GetGPUName();
    // 无法获取
    // deviceInfo["GPU Serial Number"] = GetGPUSerialNumber();
    deviceInfo["MAC Address"] = GetMACAddress();
    // 会终止
    deviceInfo["Operating System"] = GetOperatingSystem();
    deviceInfo["Memory Size"] = GetMemorySize();
    // 为空
    // deviceInfo["Memory Name"] = GetMemoryName();
    deviceInfo["Mainboard"] = GetMainboard();
    // 会终止
    // deviceInfo["Disk Partitions"] = GetDiskPartitions();
    deviceInfo["Disk Sizes"] = GetDiskSizes();

    return deviceInfo;
}
#endif 