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
include src/outputs/CMakeFiles/outputs_release.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.make

# Include the progress variables for this target.
include src/outputs/CMakeFiles/outputs_release.dir/progress.make

# Include the compile flags for this target's objects.
include src/outputs/CMakeFiles/outputs_release.dir/flags.make

src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o: /home/wanying/canoe/src/outputs/combine_blocks.cpp
src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o -MF CMakeFiles/outputs_release.dir/combine_blocks.cpp.o.d -o CMakeFiles/outputs_release.dir/combine_blocks.cpp.o -c /home/wanying/canoe/src/outputs/combine_blocks.cpp

src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/combine_blocks.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/combine_blocks.cpp > CMakeFiles/outputs_release.dir/combine_blocks.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/combine_blocks.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/combine_blocks.cpp -o CMakeFiles/outputs_release.dir/combine_blocks.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o: /home/wanying/canoe/src/outputs/debug.cpp
src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o -MF CMakeFiles/outputs_release.dir/debug.cpp.o.d -o CMakeFiles/outputs_release.dir/debug.cpp.o -c /home/wanying/canoe/src/outputs/debug.cpp

src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/debug.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/debug.cpp > CMakeFiles/outputs_release.dir/debug.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/debug.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/debug.cpp -o CMakeFiles/outputs_release.dir/debug.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o: /home/wanying/canoe/src/outputs/fits.cpp
src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o -MF CMakeFiles/outputs_release.dir/fits.cpp.o.d -o CMakeFiles/outputs_release.dir/fits.cpp.o -c /home/wanying/canoe/src/outputs/fits.cpp

src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/fits.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/fits.cpp > CMakeFiles/outputs_release.dir/fits.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/fits.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/fits.cpp -o CMakeFiles/outputs_release.dir/fits.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o: /home/wanying/canoe/src/outputs/load_user_output_data.cpp
src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o -MF CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o.d -o CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o -c /home/wanying/canoe/src/outputs/load_user_output_data.cpp

src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/load_user_output_data.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/load_user_output_data.cpp > CMakeFiles/outputs_release.dir/load_user_output_data.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/load_user_output_data.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/load_user_output_data.cpp -o CMakeFiles/outputs_release.dir/load_user_output_data.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o: /home/wanying/canoe/src/outputs/mppnccombine.cpp
src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o -MF CMakeFiles/outputs_release.dir/mppnccombine.cpp.o.d -o CMakeFiles/outputs_release.dir/mppnccombine.cpp.o -c /home/wanying/canoe/src/outputs/mppnccombine.cpp

src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/mppnccombine.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/mppnccombine.cpp > CMakeFiles/outputs_release.dir/mppnccombine.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/mppnccombine.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/mppnccombine.cpp -o CMakeFiles/outputs_release.dir/mppnccombine.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o: /home/wanying/canoe/src/outputs/netcdf.cpp
src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o -MF CMakeFiles/outputs_release.dir/netcdf.cpp.o.d -o CMakeFiles/outputs_release.dir/netcdf.cpp.o -c /home/wanying/canoe/src/outputs/netcdf.cpp

src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/netcdf.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/netcdf.cpp > CMakeFiles/outputs_release.dir/netcdf.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/netcdf.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/netcdf.cpp -o CMakeFiles/outputs_release.dir/netcdf.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o: /home/wanying/canoe/src/outputs/output_utils.cpp
src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o -MF CMakeFiles/outputs_release.dir/output_utils.cpp.o.d -o CMakeFiles/outputs_release.dir/output_utils.cpp.o -c /home/wanying/canoe/src/outputs/output_utils.cpp

src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/output_utils.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/output_utils.cpp > CMakeFiles/outputs_release.dir/output_utils.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/output_utils.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/output_utils.cpp -o CMakeFiles/outputs_release.dir/output_utils.cpp.s

src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/flags.make
src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o: /home/wanying/canoe/src/outputs/pnetcdf.cpp
src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o: src/outputs/CMakeFiles/outputs_release.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wanying/canoe/geyser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o -MF CMakeFiles/outputs_release.dir/pnetcdf.cpp.o.d -o CMakeFiles/outputs_release.dir/pnetcdf.cpp.o -c /home/wanying/canoe/src/outputs/pnetcdf.cpp

src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputs_release.dir/pnetcdf.cpp.i"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wanying/canoe/src/outputs/pnetcdf.cpp > CMakeFiles/outputs_release.dir/pnetcdf.cpp.i

src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputs_release.dir/pnetcdf.cpp.s"
	cd /home/wanying/canoe/geyser/src/outputs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wanying/canoe/src/outputs/pnetcdf.cpp -o CMakeFiles/outputs_release.dir/pnetcdf.cpp.s

outputs_release: src/outputs/CMakeFiles/outputs_release.dir/combine_blocks.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/debug.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/fits.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/load_user_output_data.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/mppnccombine.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/netcdf.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/output_utils.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/pnetcdf.cpp.o
outputs_release: src/outputs/CMakeFiles/outputs_release.dir/build.make
.PHONY : outputs_release

# Rule to build all files generated by this target.
src/outputs/CMakeFiles/outputs_release.dir/build: outputs_release
.PHONY : src/outputs/CMakeFiles/outputs_release.dir/build

src/outputs/CMakeFiles/outputs_release.dir/clean:
	cd /home/wanying/canoe/geyser/src/outputs && $(CMAKE_COMMAND) -P CMakeFiles/outputs_release.dir/cmake_clean.cmake
.PHONY : src/outputs/CMakeFiles/outputs_release.dir/clean

src/outputs/CMakeFiles/outputs_release.dir/depend:
	cd /home/wanying/canoe/geyser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wanying/canoe /home/wanying/canoe/src/outputs /home/wanying/canoe/geyser /home/wanying/canoe/geyser/src/outputs /home/wanying/canoe/geyser/src/outputs/CMakeFiles/outputs_release.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/outputs/CMakeFiles/outputs_release.dir/depend

