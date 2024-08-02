#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include "utils/WindowsDeviceInfo.h"
#else 
#include "utils/LinuxDeviceInfo.h"
#endif

#include <iostream>

int main() {
    #if defined(_WIN32) || defined(_WIN64)
    WindowsDeviceInfo deviceInfo;
    #else
    LinuxDeviceInfo deviceInfo;
    #endif

    nlohmann::json allInfoJson = deviceInfo.GetAllDeviceInfoAsJson();

    // 输出 JSON 字符串
    std::cout << allInfoJson.dump(4) << std::endl; // 使用缩进美化输出

    return 0;
}