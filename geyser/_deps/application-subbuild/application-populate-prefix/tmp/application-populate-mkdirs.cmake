# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/wanying/canoe/geyser/_deps/application-src"
  "/home/wanying/canoe/geyser/_deps/application-build"
  "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix"
  "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/tmp"
  "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/src/application-populate-stamp"
  "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/src"
  "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/src/application-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/src/application-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/wanying/canoe/geyser/_deps/application-subbuild/application-populate-prefix/src/application-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
