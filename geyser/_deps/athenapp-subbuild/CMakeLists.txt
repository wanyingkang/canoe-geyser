# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.26.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(athenapp-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.14.4]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.14.4]==]
)


include(ExternalProject)
ExternalProject_Add(athenapp-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/chengcli/athenapp/" "GIT_TAG" "snap-mods" "PATCH_COMMAND" "git" "apply" "/home/wanying/canoe/patches/19.calculate_fluxes.patch" "/home/wanying/canoe/patches/21.new_blockdt.patch" "/home/wanying/canoe/patches/23.meshblock.patch" "/home/wanying/canoe/patches/24.time_integrator.patch" "/home/wanying/canoe/patches/25.constant_acc.patch" "/home/wanying/canoe/patches/26.scalars_flux.patch" "/home/wanying/canoe/patches/26.adiabatic_hydro.patch" "/home/wanying/canoe/patches/27.coordinates.patch" "/home/wanying/canoe/patches/28.bvals_cc.patch" "/home/wanying/canoe/patches/29.mesh.patch" "/home/wanying/canoe/patches/30.bvals_base.patch" "/home/wanying/canoe/patches/31.task_list.patch" "UPDATE_DISCONNECTED" "TRUE"
                    SOURCE_DIR          "/home/wanying/canoe/geyser/_deps/athenapp-src"
                    BINARY_DIR          "/home/wanying/canoe/geyser/_deps/athenapp-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


