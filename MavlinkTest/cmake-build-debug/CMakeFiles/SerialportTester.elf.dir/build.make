# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/fabian/Software/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/fabian/Software/clion-2023.2.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SerialportTester.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SerialportTester.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SerialportTester.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SerialportTester.elf.dir/flags.make

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/DataDistributor.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/DataDistributor.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/DataDistributor.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/DataDistributor.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.s

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/EnergyCalculator.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/EnergyCalculator.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/EnergyCalculator.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/EnergyCalculator.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.s

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkHeartbeat.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkHeartbeat.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkHeartbeat.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkHeartbeat.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.s

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkSend.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkSend.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkSend.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/MavlinkSend.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.s

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SenderClass_UDP.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SenderClass_UDP.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SenderClass_UDP.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SenderClass_UDP.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.s

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SerialPort.cpp
CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SerialPort.cpp

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SerialPort.cpp > CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.i

CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/SupportFunctions/SerialPort.cpp -o CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.s

CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o: CMakeFiles/SerialportTester.elf.dir/flags.make
CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o: /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/test/Serialporttester.cpp
CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o: CMakeFiles/SerialportTester.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o -MF CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o.d -o CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o -c /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/test/Serialporttester.cpp

CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/test/Serialporttester.cpp > CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.i

CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/test/Serialporttester.cpp -o CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.s

# Object files for target SerialportTester.elf
SerialportTester_elf_OBJECTS = \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o" \
"CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o"

# External object files for target SerialportTester.elf
SerialportTester_elf_EXTERNAL_OBJECTS =

SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/DataDistributor.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/EnergyCalculator.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkHeartbeat.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/MavlinkSend.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SenderClass_UDP.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/SupportFunctions/SerialPort.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/test/Serialporttester.cpp.o
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/build.make
SerialportTester.elf: lib/Catch2/src/libCatch2Maind.a
SerialportTester.elf: lib/Catch2/src/libCatch2d.a
SerialportTester.elf: CMakeFiles/SerialportTester.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SerialportTester.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SerialportTester.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SerialportTester.elf.dir/build: SerialportTester.elf
.PHONY : CMakeFiles/SerialportTester.elf.dir/build

CMakeFiles/SerialportTester.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SerialportTester.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SerialportTester.elf.dir/clean

CMakeFiles/SerialportTester.elf.dir/depend:
	cd /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug /home/fabian/Soaring/cpp_soaring/autonomous-soaring/MavlinkTest/cmake-build-debug/CMakeFiles/SerialportTester.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SerialportTester.elf.dir/depend

