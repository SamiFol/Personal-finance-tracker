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
CMAKE_SOURCE_DIR = /home/samsepi0l/personalfinancetracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samsepi0l/personalfinancetracker/build

# Include any dependencies generated for this target.
include CMakeFiles/finance_tracker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/finance_tracker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/finance_tracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/finance_tracker.dir/flags.make

CMakeFiles/finance_tracker.dir/src/main.cpp.o: CMakeFiles/finance_tracker.dir/flags.make
CMakeFiles/finance_tracker.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/finance_tracker.dir/src/main.cpp.o: CMakeFiles/finance_tracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samsepi0l/personalfinancetracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/finance_tracker.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/finance_tracker.dir/src/main.cpp.o -MF CMakeFiles/finance_tracker.dir/src/main.cpp.o.d -o CMakeFiles/finance_tracker.dir/src/main.cpp.o -c /home/samsepi0l/personalfinancetracker/src/main.cpp

CMakeFiles/finance_tracker.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/finance_tracker.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samsepi0l/personalfinancetracker/src/main.cpp > CMakeFiles/finance_tracker.dir/src/main.cpp.i

CMakeFiles/finance_tracker.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/finance_tracker.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samsepi0l/personalfinancetracker/src/main.cpp -o CMakeFiles/finance_tracker.dir/src/main.cpp.s

# Object files for target finance_tracker
finance_tracker_OBJECTS = \
"CMakeFiles/finance_tracker.dir/src/main.cpp.o"

# External object files for target finance_tracker
finance_tracker_EXTERNAL_OBJECTS =

finance_tracker: CMakeFiles/finance_tracker.dir/src/main.cpp.o
finance_tracker: CMakeFiles/finance_tracker.dir/build.make
finance_tracker: CMakeFiles/finance_tracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samsepi0l/personalfinancetracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable finance_tracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/finance_tracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/finance_tracker.dir/build: finance_tracker
.PHONY : CMakeFiles/finance_tracker.dir/build

CMakeFiles/finance_tracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/finance_tracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/finance_tracker.dir/clean

CMakeFiles/finance_tracker.dir/depend:
	cd /home/samsepi0l/personalfinancetracker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samsepi0l/personalfinancetracker /home/samsepi0l/personalfinancetracker /home/samsepi0l/personalfinancetracker/build /home/samsepi0l/personalfinancetracker/build /home/samsepi0l/personalfinancetracker/build/CMakeFiles/finance_tracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/finance_tracker.dir/depend

