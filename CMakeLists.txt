cmake_minimum_required(VERSION 3.10)
project(HardwareInfo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 初始化源文件变量
set(SOURCE_FILES src/main.cpp )

# 根据操作系统添加相应的源文件
if(WIN32)
    list(APPEND SOURCE_FILES src/utils/WindowsDeviceInfo.cpp)
    add_definitions(-DWIN32)
elseif(UNIX AND NOT APPLE)
    list(APPEND SOURCE_FILES src/utils/LinuxDeviceInfo.cpp)
    add_definitions(-D__LINUX__)
endif()

# 添加可执行文件
add_executable(HardwareInfo ${SOURCE_FILES})

# 根据不同的操作系统，链接特定的库
if(WIN32)
    target_link_libraries(HardwareInfo dxgi d3d11)
elseif(UNIX AND NOT APPLE)
    # 这里可以添加Linux特有的库
endif()
