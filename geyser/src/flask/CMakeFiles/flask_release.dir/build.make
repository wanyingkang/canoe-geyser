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
CMAKE_COMMAND = /home/software/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /home/software/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wanying/canoe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wanying/canoe/geyser

# Include any dependencies generated for this target.
include src/flask/CMakeFiles/flask_release.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/flask/CMakeFiles/flask_release.dir/compiler_depend.make

# Include the progress variables for this target.
include src/flask/CMakeFiles/flask_release.dir/progress.make

# Include the compile flags for this target's objects.
include src/flask/CMakeFiles/flask_release.dir/flags.make

src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o: src/flask/CMakeFiles/flask_release.dir/flags.make
src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o: /home/wanying/canoe/src/flask/chemistry.cpp
src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o: src/flask/CMakeFiles/flask_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o"
	cd /home/wanying/canoe/geyser/src/flask && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o -MF CMakeFiles/flask_release.dir/chemistry.cpp.o.d -o CMakeFiles/flask_release.dir/chemistry.cpp.o -c /home/wanying/canoe/src/flask/chemistry.cpp

src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flask_release.dir/chemistry.cpp.i"
	cd /home/wanying/canoe/geyser/src/flask && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/flask/chemistry.cpp > CMakeFiles/flask_release.dir/chemistry.cpp.i

src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flask_release.dir/chemistry.cpp.s"
	cd /home/wanying/canoe/geyser/src/flask && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/flask/chemistry.cpp -o CMakeFiles/flask_release.dir/chemistry.cpp.s

flask_release: src/flask/CMakeFiles/flask_release.dir/chemistry.cpp.o
flask_release: src/flask/CMakeFiles/flask_release.dir/build.make
.PHONY : flask_release

# Rule to build all files generated by this target.
src/flask/CMakeFiles/flask_release.dir/build: flask_release
.PHONY : src/flask/CMakeFiles/flask_release.dir/build

src/flask/CMakeFiles/flask_release.dir/clean:
	cd /home/wanying/canoe/geyser/src/flask && $(CMAKE_COMMAND) -P CMakeFiles/flask_release.dir/cmake_clean.cmake
.PHONY : src/flask/CMakeFiles/flask_release.dir/clean

src/flask/CMakeFiles/flask_release.dir/depend:
	cd /home/wanying/canoe/geyser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanying/canoe /home/wanying/canoe/src/flask /home/wanying/canoe/geyser /home/wanying/canoe/geyser/src/flask /home/wanying/canoe/geyser/src/flask/CMakeFiles/flask_release.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/flask/CMakeFiles/flask_release.dir/depend

