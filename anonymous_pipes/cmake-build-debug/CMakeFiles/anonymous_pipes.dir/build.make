# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/anonymous_pipes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/anonymous_pipes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/anonymous_pipes.dir/flags.make

CMakeFiles/anonymous_pipes.dir/main.cpp.o: CMakeFiles/anonymous_pipes.dir/flags.make
CMakeFiles/anonymous_pipes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/anonymous_pipes.dir/main.cpp.o"
	/usr/local/Cellar/gcc/10.2.0/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/anonymous_pipes.dir/main.cpp.o -c "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/main.cpp"

CMakeFiles/anonymous_pipes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anonymous_pipes.dir/main.cpp.i"
	/usr/local/Cellar/gcc/10.2.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/main.cpp" > CMakeFiles/anonymous_pipes.dir/main.cpp.i

CMakeFiles/anonymous_pipes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anonymous_pipes.dir/main.cpp.s"
	/usr/local/Cellar/gcc/10.2.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/main.cpp" -o CMakeFiles/anonymous_pipes.dir/main.cpp.s

# Object files for target anonymous_pipes
anonymous_pipes_OBJECTS = \
"CMakeFiles/anonymous_pipes.dir/main.cpp.o"

# External object files for target anonymous_pipes
anonymous_pipes_EXTERNAL_OBJECTS =

anonymous_pipes: CMakeFiles/anonymous_pipes.dir/main.cpp.o
anonymous_pipes: CMakeFiles/anonymous_pipes.dir/build.make
anonymous_pipes: CMakeFiles/anonymous_pipes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable anonymous_pipes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/anonymous_pipes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/anonymous_pipes.dir/build: anonymous_pipes

.PHONY : CMakeFiles/anonymous_pipes.dir/build

CMakeFiles/anonymous_pipes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/anonymous_pipes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/anonymous_pipes.dir/clean

CMakeFiles/anonymous_pipes.dir/depend:
	cd "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes" "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes" "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug" "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug" "/Users/herbertma/Downloads/Client Server Final Exam Prep/anonymous_pipes/cmake-build-debug/CMakeFiles/anonymous_pipes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/anonymous_pipes.dir/depend

