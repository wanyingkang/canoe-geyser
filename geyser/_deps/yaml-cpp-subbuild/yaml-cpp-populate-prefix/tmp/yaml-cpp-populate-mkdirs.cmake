# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-src"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-build"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/tmp"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src"
  "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/wanying/canoe/geyser/_deps/yaml-cpp-subbuild/yaml-cpp-populate-prefix/src/yaml-cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
