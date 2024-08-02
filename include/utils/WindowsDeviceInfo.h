#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifndef WINDOWS_DEVICE_INFO_H
#define WINDOWS_DEVICE_INFO_H


#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>
#include <string>
#include <vector>
#include <json.hpp>
#pragma comment(lib, "wbemuuid.lib")

class WindowsDeviceInfo {
public:
    WindowsDeviceInfo();
    ~WindowsDeviceInfo();

    std::string GetCpuId();
    std::string GetCpuName();
    std::string GetDiskSerialNumber();
    std::string GetGPUName();
    std::string GetGPUSerialNumber();
    std::string GetMACAddress();
    std::string GetOperatingSystem();
    std::string GetMemorySize();
    std::string GetMemoryName();
    std::string GetMainboard();
    std::vector<std::string> GetDiskPartitions();
    std::vector<std::string> GetDiskSizes();

    nlohmann::json GetAllDeviceInfoAsJson();


private:
    IWbemLocator *pLocator = NULL;
    IWbemServices *pServices = NULL;

    bool InitializeCOM();
    void UninitializeCOM();
    bool ConnectToWMI();
    void DisconnectFromWMI();

    std::string QueryWMI(const std::wstring& query, const std::wstring& property);
    std::vector<std::string> QueryWMIMultiple(const std::wstring& query, const std::wstring& property);
};

#endif
#endif