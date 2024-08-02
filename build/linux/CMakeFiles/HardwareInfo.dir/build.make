# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/hardware-info

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/hardware-info/build/linux

# Include any dependencies generated for this target.
include CMakeFiles/HardwareInfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HardwareInfo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HardwareInfo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HardwareInfo.dir/flags.make

CMakeFiles/HardwareInfo.dir/src/main.cpp.o: CMakeFiles/HardwareInfo.dir/flags.make
CMakeFiles/HardwareInfo.dir/src/main.cpp.o: ../../src/main.cpp
CMakeFiles/HardwareInfo.dir/src/main.cpp.o: CMakeFiles/HardwareInfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/hardware-info/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HardwareInfo.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HardwareInfo.dir/src/main.cpp.o -MF CMakeFiles/HardwareInfo.dir/src/main.cpp.o.d -o CMakeFiles/HardwareInfo.dir/src/main.cpp.o -c /mnt/hgfs/hardware-info/src/main.cpp

CMakeFiles/HardwareInfo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HardwareInfo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/hardware-info/src/main.cpp > CMakeFiles/HardwareInfo.dir/src/main.cpp.i

CMakeFiles/HardwareInfo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HardwareInfo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/hardware-info/src/main.cpp -o CMakeFiles/HardwareInfo.dir/src/main.cpp.s

CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o: CMakeFiles/HardwareInfo.dir/flags.make
CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o: ../../src/utils/LinuxDeviceInfo.cpp
CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o: CMakeFiles/HardwareInfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/hardware-info/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o -MF CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o.d -o CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o -c /mnt/hgfs/hardware-info/src/utils/LinuxDeviceInfo.cpp

CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/hardware-info/src/utils/LinuxDeviceInfo.cpp > CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.i

CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/hardware-info/src/utils/LinuxDeviceInfo.cpp -o CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.s

# Object files for target HardwareInfo
HardwareInfo_OBJECTS = \
"CMakeFiles/HardwareInfo.dir/src/main.cpp.o" \
"CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o"

# External object files for target HardwareInfo
HardwareInfo_EXTERNAL_OBJECTS =

HardwareInfo: CMakeFiles/HardwareInfo.dir/src/main.cpp.o
HardwareInfo: CMakeFiles/HardwareInfo.dir/src/utils/LinuxDeviceInfo.cpp.o
HardwareInfo: CMakeFiles/HardwareInfo.dir/build.make
HardwareInfo: CMakeFiles/HardwareInfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/hardware-info/build/linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HardwareInfo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HardwareInfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HardwareInfo.dir/build: HardwareInfo
.PHONY : CMakeFiles/HardwareInfo.dir/build

CMakeFiles/HardwareInfo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HardwareInfo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HardwareInfo.dir/clean

CMakeFiles/HardwareInfo.dir/depend:
	cd /mnt/hgfs/hardware-info/build/linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/hardware-info /mnt/hgfs/hardware-info /mnt/hgfs/hardware-info/build/linux /mnt/hgfs/hardware-info/build/linux /mnt/hgfs/hardware-info/build/linux/CMakeFiles/HardwareInfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HardwareInfo.dir/depend
