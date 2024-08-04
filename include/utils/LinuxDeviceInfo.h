#ifndef LINUX_DEVICE_INFO_H
#define LINUX_DEVICE_INFO_H

#include <string>
#include <vector>
#include "json.hpp"
std::string ExecuteCommand(const char* cmd);
std::vector<std::string> ExecuteCommandAndSplit(const char* cmd, char delimiter);
std::vector<std::string> GetNetworkInterfaces();
class LinuxDeviceInfo {
public:
    LinuxDeviceInfo();
    ~LinuxDeviceInfo();

    std::string GetCpuInfo();
    std::string GetDiskSerialNumber();
    std::vector<std::string> GetDiskPartitions();
    std::string GetGPUInfo();
    std::string GetMacAddress();
    std::string GetOperatingSystem();
    std::string GetMemoryInfo();
    std::string GetMainboardInfo();
    nlohmann::json GetAllDeviceInfoAsJson();
};

#endif
