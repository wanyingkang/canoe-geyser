# set up test cases ##

string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

# Enable testing functionality
enable_testing()

file(GLOB src_files *.cpp)

foreach(test ${src_files})
  get_filename_component(name ${test} NAME_WE)
  add_executable(${name}.${buildl} ${name}.cpp)
  set_target_properties(${name}.${buildl}
                        PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_${buildu}})

  target_include_directories(${name}.${buildl}
                             PRIVATE ${APPLICATION_INCLUDE_DIR})

  target_link_libraries(${name}.${buildl} application_${buildl} banner)
  add_test(NAME ${name}.${buildl} COMMAND ${name}.${buildl})
endforeach()
