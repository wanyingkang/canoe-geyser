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
include src/CMakeFiles/canoe_release.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/canoe_release.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/canoe_release.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/canoe_release.dir/flags.make

src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o: /home/wanying/canoe/src/air_parcel.cpp
src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o -MF CMakeFiles/canoe_release.dir/air_parcel.cpp.o.d -o CMakeFiles/canoe_release.dir/air_parcel.cpp.o -c /home/wanying/canoe/src/air_parcel.cpp

src/CMakeFiles/canoe_release.dir/air_parcel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/air_parcel.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/air_parcel.cpp > CMakeFiles/canoe_release.dir/air_parcel.cpp.i

src/CMakeFiles/canoe_release.dir/air_parcel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/air_parcel.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/air_parcel.cpp -o CMakeFiles/canoe_release.dir/air_parcel.cpp.s

src/CMakeFiles/canoe_release.dir/checks.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/checks.cpp.o: /home/wanying/canoe/src/checks.cpp
src/CMakeFiles/canoe_release.dir/checks.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/canoe_release.dir/checks.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/checks.cpp.o -MF CMakeFiles/canoe_release.dir/checks.cpp.o.d -o CMakeFiles/canoe_release.dir/checks.cpp.o -c /home/wanying/canoe/src/checks.cpp

src/CMakeFiles/canoe_release.dir/checks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/checks.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/checks.cpp > CMakeFiles/canoe_release.dir/checks.cpp.i

src/CMakeFiles/canoe_release.dir/checks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/checks.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/checks.cpp -o CMakeFiles/canoe_release.dir/checks.cpp.s

src/CMakeFiles/canoe_release.dir/impl.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/impl.cpp.o: /home/wanying/canoe/src/impl.cpp
src/CMakeFiles/canoe_release.dir/impl.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/canoe_release.dir/impl.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/impl.cpp.o -MF CMakeFiles/canoe_release.dir/impl.cpp.o.d -o CMakeFiles/canoe_release.dir/impl.cpp.o -c /home/wanying/canoe/src/impl.cpp

src/CMakeFiles/canoe_release.dir/impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/impl.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/impl.cpp > CMakeFiles/canoe_release.dir/impl.cpp.i

src/CMakeFiles/canoe_release.dir/impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/impl.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/impl.cpp -o CMakeFiles/canoe_release.dir/impl.cpp.s

src/CMakeFiles/canoe_release.dir/index_map.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/index_map.cpp.o: /home/wanying/canoe/src/index_map.cpp
src/CMakeFiles/canoe_release.dir/index_map.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/canoe_release.dir/index_map.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/index_map.cpp.o -MF CMakeFiles/canoe_release.dir/index_map.cpp.o.d -o CMakeFiles/canoe_release.dir/index_map.cpp.o -c /home/wanying/canoe/src/index_map.cpp

src/CMakeFiles/canoe_release.dir/index_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/index_map.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/index_map.cpp > CMakeFiles/canoe_release.dir/index_map.cpp.i

src/CMakeFiles/canoe_release.dir/index_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/index_map.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/index_map.cpp -o CMakeFiles/canoe_release.dir/index_map.cpp.s

src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o: /home/wanying/canoe/src/mesh_destroy.cpp
src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o -MF CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o.d -o CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o -c /home/wanying/canoe/src/mesh_destroy.cpp

src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/mesh_destroy.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/mesh_destroy.cpp > CMakeFiles/canoe_release.dir/mesh_destroy.cpp.i

src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/mesh_destroy.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/mesh_destroy.cpp -o CMakeFiles/canoe_release.dir/mesh_destroy.cpp.s

src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o: /home/wanying/canoe/src/mesh_setup.cpp
src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o -MF CMakeFiles/canoe_release.dir/mesh_setup.cpp.o.d -o CMakeFiles/canoe_release.dir/mesh_setup.cpp.o -c /home/wanying/canoe/src/mesh_setup.cpp

src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/mesh_setup.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/mesh_setup.cpp > CMakeFiles/canoe_release.dir/mesh_setup.cpp.i

src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/mesh_setup.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/mesh_setup.cpp -o CMakeFiles/canoe_release.dir/mesh_setup.cpp.s

src/CMakeFiles/canoe_release.dir/schedulers.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/schedulers.cpp.o: /home/wanying/canoe/src/schedulers.cpp
src/CMakeFiles/canoe_release.dir/schedulers.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/canoe_release.dir/schedulers.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/schedulers.cpp.o -MF CMakeFiles/canoe_release.dir/schedulers.cpp.o.d -o CMakeFiles/canoe_release.dir/schedulers.cpp.o -c /home/wanying/canoe/src/schedulers.cpp

src/CMakeFiles/canoe_release.dir/schedulers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/schedulers.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/schedulers.cpp > CMakeFiles/canoe_release.dir/schedulers.cpp.i

src/CMakeFiles/canoe_release.dir/schedulers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/schedulers.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/schedulers.cpp -o CMakeFiles/canoe_release.dir/schedulers.cpp.s

src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o: src/CMakeFiles/canoe_release.dir/flags.make
src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o: /home/wanying/canoe/src/virtual_groups.cpp
src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o: src/CMakeFiles/canoe_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o -MF CMakeFiles/canoe_release.dir/virtual_groups.cpp.o.d -o CMakeFiles/canoe_release.dir/virtual_groups.cpp.o -c /home/wanying/canoe/src/virtual_groups.cpp

src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canoe_release.dir/virtual_groups.cpp.i"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/virtual_groups.cpp > CMakeFiles/canoe_release.dir/virtual_groups.cpp.i

src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canoe_release.dir/virtual_groups.cpp.s"
	cd /home/wanying/canoe/geyser/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/virtual_groups.cpp -o CMakeFiles/canoe_release.dir/virtual_groups.cpp.s

canoe_release: src/CMakeFiles/canoe_release.dir/air_parcel.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/checks.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/impl.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/index_map.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/mesh_destroy.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/mesh_setup.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/schedulers.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/virtual_groups.cpp.o
canoe_release: src/CMakeFiles/canoe_release.dir/build.make
.PHONY : canoe_release

# Rule to build all files generated by this target.
src/CMakeFiles/canoe_release.dir/build: canoe_release
.PHONY : src/CMakeFiles/canoe_release.dir/build

src/CMakeFiles/canoe_release.dir/clean:
	cd /home/wanying/canoe/geyser/src && $(CMAKE_COMMAND) -P CMakeFiles/canoe_release.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/canoe_release.dir/clean

src/CMakeFiles/canoe_release.dir/depend:
	cd /home/wanying/canoe/geyser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanying/canoe /home/wanying/canoe/src /home/wanying/canoe/geyser /home/wanying/canoe/geyser/src /home/wanying/canoe/geyser/src/CMakeFiles/canoe_release.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/canoe_release.dir/depend
