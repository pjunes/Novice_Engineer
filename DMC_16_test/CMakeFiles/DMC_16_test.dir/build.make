# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pjunes/Projects/DMC_16_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pjunes/Projects/DMC_16_test

# Include any dependencies generated for this target.
include CMakeFiles/DMC_16_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DMC_16_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DMC_16_test.dir/flags.make

CMakeFiles/DMC_16_test.dir/main.cpp.o: CMakeFiles/DMC_16_test.dir/flags.make
CMakeFiles/DMC_16_test.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pjunes/Projects/DMC_16_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DMC_16_test.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DMC_16_test.dir/main.cpp.o -c /home/pjunes/Projects/DMC_16_test/main.cpp

CMakeFiles/DMC_16_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMC_16_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pjunes/Projects/DMC_16_test/main.cpp > CMakeFiles/DMC_16_test.dir/main.cpp.i

CMakeFiles/DMC_16_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMC_16_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pjunes/Projects/DMC_16_test/main.cpp -o CMakeFiles/DMC_16_test.dir/main.cpp.s

# Object files for target DMC_16_test
DMC_16_test_OBJECTS = \
"CMakeFiles/DMC_16_test.dir/main.cpp.o"

# External object files for target DMC_16_test
DMC_16_test_EXTERNAL_OBJECTS =

bin/DMC_16_test: CMakeFiles/DMC_16_test.dir/main.cpp.o
bin/DMC_16_test: CMakeFiles/DMC_16_test.dir/build.make
bin/DMC_16_test: /usr/local/lib/libwiringPi.so
bin/DMC_16_test: CMakeFiles/DMC_16_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pjunes/Projects/DMC_16_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/DMC_16_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DMC_16_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DMC_16_test.dir/build: bin/DMC_16_test

.PHONY : CMakeFiles/DMC_16_test.dir/build

CMakeFiles/DMC_16_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DMC_16_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DMC_16_test.dir/clean

CMakeFiles/DMC_16_test.dir/depend:
	cd /home/pjunes/Projects/DMC_16_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pjunes/Projects/DMC_16_test /home/pjunes/Projects/DMC_16_test /home/pjunes/Projects/DMC_16_test /home/pjunes/Projects/DMC_16_test /home/pjunes/Projects/DMC_16_test/CMakeFiles/DMC_16_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DMC_16_test.dir/depend

