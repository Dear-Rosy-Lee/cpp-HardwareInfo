# 项目环境信息收集

本项目负责`windows/linux`收集运行环境的硬件信息，包括CPU、硬盘、网卡地址等。该信息将用于系统配置和性能优化分析。

## 收集的信息详情

以下表格列出了本项目将会收集的硬件信息字段及其说明：

| 字段名         | 字段说明         |
| -------------- | ---------------- |
| `CPU_SN`       | CPU 序列号       |
| `CPU_Name`     | CPU 名称         |
| `DISK_SN`      | 硬盘序列号       |
| `DISK_Partition` | 磁盘分区       |
| `DISK_Size`    | 硬盘容量大小     |
| `GPU_Name`     | 显卡名称         |
| `GPU_SN`       | 显卡序列号       |
| `MAC`          | 硬件地址         |
| `OperationSystem` | 操作系统      |
| `Memory_Size`  | 内存大小         |
| `Memory_Name`  | 内存名称         |
| `Mainboard`    | 主板             |

## 特殊说明

- 如果系统中存在多个CPU或磁盘，信息将会被排序，并且只选择第一个CPU和非移动硬盘。
- 对于拥有多个CPU或内存条的系统，相关信息将以数组的形式存储。
- 所有收集到的信息最终将以JSON格式的字符串形式输出。

该信息收集功能对于理解系统配置和进行故障排查是非常有用的。

## 运行
`windows`

在项目根目录中运行以下命令,其中`--config Release`中的Release可以改成Debug等$name$，编译出的可执行程序即在/build/windows/$name$中

~~~ command
cd build\windows
cmake ../..
cmake --build . --clean-first --config Release
~~~

`linux`

在项目根目录中运行以下命令
~~~ command
cd build/linux
rm -rf ./*
cmake ../..
make
~~~