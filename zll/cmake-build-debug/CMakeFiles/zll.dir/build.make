# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/tr/Downloads/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tr/Downloads/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tr/Desktop/zll

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tr/Desktop/zll/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zll.dir/flags.make

CMakeFiles/zll.dir/zll.cpp.o: CMakeFiles/zll.dir/flags.make
CMakeFiles/zll.dir/zll.cpp.o: ../zll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tr/Desktop/zll/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zll.dir/zll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zll.dir/zll.cpp.o -c /home/tr/Desktop/zll/zll.cpp

CMakeFiles/zll.dir/zll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zll.dir/zll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tr/Desktop/zll/zll.cpp > CMakeFiles/zll.dir/zll.cpp.i

CMakeFiles/zll.dir/zll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zll.dir/zll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tr/Desktop/zll/zll.cpp -o CMakeFiles/zll.dir/zll.cpp.s

# Object files for target zll
zll_OBJECTS = \
"CMakeFiles/zll.dir/zll.cpp.o"

# External object files for target zll
zll_EXTERNAL_OBJECTS =

zll: CMakeFiles/zll.dir/zll.cpp.o
zll: CMakeFiles/zll.dir/build.make
zll: CMakeFiles/zll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tr/Desktop/zll/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zll.dir/build: zll

.PHONY : CMakeFiles/zll.dir/build

CMakeFiles/zll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zll.dir/clean

CMakeFiles/zll.dir/depend:
	cd /home/tr/Desktop/zll/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tr/Desktop/zll /home/tr/Desktop/zll /home/tr/Desktop/zll/cmake-build-debug /home/tr/Desktop/zll/cmake-build-debug /home/tr/Desktop/zll/cmake-build-debug/CMakeFiles/zll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zll.dir/depend
