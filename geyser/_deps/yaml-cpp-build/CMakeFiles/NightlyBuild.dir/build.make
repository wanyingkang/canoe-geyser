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

# Utility rule file for NightlyBuild.

# Include any custom commands dependencies for this target.
include _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/progress.make

_deps/yaml-cpp-build/CMakeFiles/NightlyBuild:
	cd /home/wanying/canoe/geyser/_deps/yaml-cpp-build && /home/software/cmake/3.26.4/bin/ctest -D NightlyBuild

NightlyBuild: _deps/yaml-cpp-build/CMakeFiles/NightlyBuild
NightlyBuild: _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/build.make
.PHONY : NightlyBuild

# Rule to build all files generated by this target.
_deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/build: NightlyBuild
.PHONY : _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/build

_deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/clean:
	cd /home/wanying/canoe/geyser/_deps/yaml-cpp-build && $(CMAKE_COMMAND) -P CMakeFiles/NightlyBuild.dir/cmake_clean.cmake
.PHONY : _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/clean

_deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/depend:
	cd /home/wanying/canoe/geyser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanying/canoe /home/wanying/canoe/geyser/_deps/yaml-cpp-src /home/wanying/canoe/geyser /home/wanying/canoe/geyser/_deps/yaml-cpp-build /home/wanying/canoe/geyser/_deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/yaml-cpp-build/CMakeFiles/NightlyBuild.dir/depend

