cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(application LANGUAGES CXX)
message(STATUS "")
message(STATUS "== Setting up application library ==")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message(STATUS "Default Build Type = Release")
  message(STATUS "")
else()
  message(STATUS "Build Type = ${CMAKE_BUILD_TYPE}")
  message(STATUS "")
endif()

# 1. set up compiler flags ##
message(STATUS "1. Set up project compiler flags ...")
message(STATUS "Include ${CMAKE_SOURCE_DIR}/cmake/compilers.cmake")
include(${CMAKE_SOURCE_DIR}/cmake/compilers.cmake)

# 1. set up project configuration ##
message(STATUS "2. Set up project specific configuration ...")
message(STATUS "Include ${CMAKE_SOURCE_DIR}/cmake/parameters.cmake")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/parameters.cmake)

# 1. Set up project system libraries ##
message(STATUS "3. Set up project banner ...")
add_library(banner STATIC banner.cpp)

# 1. Set up project configure file and library ##
message(STATUS "4. Set up project libraries")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/globals.hpp.in
               ${CMAKE_CURRENT_SOURCE_DIR}/src/globals.hpp @ONLY)
add_subdirectory(src)

set(APPLICATION_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
    CACHE PATH "application include directory")
mark_as_advanced(APPLICATION_INCLUDE_DIR)

# 1. set up unit tests
message(STATUS "5. Set up unit tests")
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(tests)
endif()
