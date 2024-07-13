# ==============================
# Create the application library
# ==============================

set(namel application)
string(TOUPPER ${namel} nameu)

file(GLOB src_files *.cpp)

string(TOLOWER ${CMAKE_BUILD_TYPE} buildl)
string(TOUPPER ${CMAKE_BUILD_TYPE} buildu)

add_library(${namel}_${buildl} STATIC ${src_files})

set_target_properties(${namel}_${buildl} PROPERTIES COMPILE_FLAGS
                                                    ${CMAKE_C_FLAGS_${buildu}})
target_include_directories(${namel}_${buildl}
  SYSTEM PRIVATE
  ${MPI_CXX_INCLUDE_PATH}
  )

target_link_libraries(${namel}_${buildl}
  ${MPI_CXX_LIBRARIES}
  )
