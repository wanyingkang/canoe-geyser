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
include src/inversion/CMakeFiles/inversion_release.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/inversion/CMakeFiles/inversion_release.dir/compiler_depend.make

# Include the progress variables for this target.
include src/inversion/CMakeFiles/inversion_release.dir/progress.make

# Include the compile flags for this target's objects.
include src/inversion/CMakeFiles/inversion_release.dir/flags.make

src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/flags.make
src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o: /home/wanying/canoe/src/inversion/composition_inversion.cpp
src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o -MF CMakeFiles/inversion_release.dir/composition_inversion.cpp.o.d -o CMakeFiles/inversion_release.dir/composition_inversion.cpp.o -c /home/wanying/canoe/src/inversion/composition_inversion.cpp

src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inversion_release.dir/composition_inversion.cpp.i"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/inversion/composition_inversion.cpp > CMakeFiles/inversion_release.dir/composition_inversion.cpp.i

src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inversion_release.dir/composition_inversion.cpp.s"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/inversion/composition_inversion.cpp -o CMakeFiles/inversion_release.dir/composition_inversion.cpp.s

src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/flags.make
src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o: /home/wanying/canoe/src/inversion/gaussian_process.cpp
src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o -MF CMakeFiles/inversion_release.dir/gaussian_process.cpp.o.d -o CMakeFiles/inversion_release.dir/gaussian_process.cpp.o -c /home/wanying/canoe/src/inversion/gaussian_process.cpp

src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inversion_release.dir/gaussian_process.cpp.i"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/inversion/gaussian_process.cpp > CMakeFiles/inversion_release.dir/gaussian_process.cpp.i

src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inversion_release.dir/gaussian_process.cpp.s"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/inversion/gaussian_process.cpp -o CMakeFiles/inversion_release.dir/gaussian_process.cpp.s

src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/flags.make
src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o: /home/wanying/canoe/src/inversion/inversion_factory.cpp
src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o -MF CMakeFiles/inversion_release.dir/inversion_factory.cpp.o.d -o CMakeFiles/inversion_release.dir/inversion_factory.cpp.o -c /home/wanying/canoe/src/inversion/inversion_factory.cpp

src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inversion_release.dir/inversion_factory.cpp.i"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/inversion/inversion_factory.cpp > CMakeFiles/inversion_release.dir/inversion_factory.cpp.i

src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inversion_release.dir/inversion_factory.cpp.s"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/inversion/inversion_factory.cpp -o CMakeFiles/inversion_release.dir/inversion_factory.cpp.s

src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/flags.make
src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o: /home/wanying/canoe/src/inversion/profile_inversion.cpp
src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o: src/inversion/CMakeFiles/inversion_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o -MF CMakeFiles/inversion_release.dir/profile_inversion.cpp.o.d -o CMakeFiles/inversion_release.dir/profile_inversion.cpp.o -c /home/wanying/canoe/src/inversion/profile_inversion.cpp

src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inversion_release.dir/profile_inversion.cpp.i"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/inversion/profile_inversion.cpp > CMakeFiles/inversion_release.dir/profile_inversion.cpp.i

src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inversion_release.dir/profile_inversion.cpp.s"
	cd /home/wanying/canoe/geyser/src/inversion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/inversion/profile_inversion.cpp -o CMakeFiles/inversion_release.dir/profile_inversion.cpp.s

inversion_release: src/inversion/CMakeFiles/inversion_release.dir/composition_inversion.cpp.o
inversion_release: src/inversion/CMakeFiles/inversion_release.dir/gaussian_process.cpp.o
inversion_release: src/inversion/CMakeFiles/inversion_release.dir/inversion_factory.cpp.o
inversion_release: src/inversion/CMakeFiles/inversion_release.dir/profile_inversion.cpp.o
inversion_release: src/inversion/CMakeFiles/inversion_release.dir/build.make
.PHONY : inversion_release

# Rule to build all files generated by this target.
src/inversion/CMakeFiles/inversion_release.dir/build: inversion_release
.PHONY : src/inversion/CMakeFiles/inversion_release.dir/build

src/inversion/CMakeFiles/inversion_release.dir/clean:
	cd /home/wanying/canoe/geyser/src/inversion && $(CMAKE_COMMAND) -P CMakeFiles/inversion_release.dir/cmake_clean.cmake
.PHONY : src/inversion/CMakeFiles/inversion_release.dir/clean

src/inversion/CMakeFiles/inversion_release.dir/depend:
	cd /home/wanying/canoe/geyser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanying/canoe /home/wanying/canoe/src/inversion /home/wanying/canoe/geyser /home/wanying/canoe/geyser/src/inversion /home/wanying/canoe/geyser/src/inversion/CMakeFiles/inversion_release.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/inversion/CMakeFiles/inversion_release.dir/depend
