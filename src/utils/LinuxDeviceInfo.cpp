#if defined(__linux__) || defined(__unix__) 
#include <iostream>
#include <sstream>
#include <array>
#include "utils/LinuxDeviceInfo.h"

LinuxDeviceInfo::LinuxDeviceInfo() {}

LinuxDeviceInfo::~LinuxDeviceInfo() {}

std::string LinuxDeviceInfo::GetCpuInfo() {
    return ExecuteCommand("cat /proc/cpuinfo | grep 'model name' | uniq | cut -d ':' -f2");
}

std::string LinuxDeviceInfo::GetDiskSerialNumber() {
    return ExecuteCommand("sudo hdparm -I /dev/sda | grep 'Serial Number' | cut -d ':' -f2");
}

std::vector<std::string> LinuxDeviceInfo::GetDiskPartitions() {
    return ExecuteCommandAndSplit("lsblk -no NAME /dev/sda", '\n');
}

std::string LinuxDeviceInfo::GetGPUInfo() {
    return ExecuteCommand("lspci | grep -i 'vga\\|3d\\|2d'");
}

std::string LinuxDeviceInfo::GetMacAddress() {
    return ExecuteCommand("cat /sys/class/net/eth0/address");
}

std::string LinuxDeviceInfo::GetOperatingSystem() {
    return ExecuteCommand("uname -o");
}

std::string LinuxDeviceInfo::GetMemoryInfo() {
    return ExecuteCommand("cat /proc/meminfo | grep 'MemTotal:'");
}

std::string LinuxDeviceInfo::GetMainboardInfo() {
    return "Mainboard information typically requires specific tools like dmidecode.";
}

nlohmann::json LinuxDeviceInfo::GetAllDeviceInfoAsJson() {
    nlohmann::json deviceInfo;
    deviceInfo["CPU Info"] = GetCpuInfo();
    deviceInfo["Disk Serial Number"] = GetDiskSerialNumber();
    deviceInfo["GPU Info"] = GetGPUInfo();
    deviceInfo["MAC Address"] = GetMacAddress();
    deviceInfo["Operating System"] = GetOperatingSystem();
    deviceInfo["Memory Info"] = GetMemoryInfo();
    deviceInfo["Mainboard Info"] = GetMainboardInfo();
    deviceInfo["Disk Partitions"] = GetDiskPartitions();
    return deviceInfo;
}

std::string LinuxDeviceInfo::ExecuteCommand(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        return "Failed to run command";
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::vector<std::string> LinuxDeviceInfo::ExecuteCommandAndSplit(const char* cmd, char delimiter) {
    std::string output = ExecuteCommand(cmd);
    std::vector<std::string> results;
    std::stringstream ss(output);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        results.push_back(item);
    }
    return results;
}
#endif
