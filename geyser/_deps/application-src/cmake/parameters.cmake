# define default parameters

macro(SET_IF_EMPTY _variable)
  if("${${_variable}}" STREQUAL "")
    set(${_variable} ${ARGN})
  endif()
endmacro()

# populate the default values
SET_IF_EMPTY(WINDOWS_SYSTEM "NOT_WINDOWS")

SET_IF_EMPTY(MYPATH "")

# MPI parallelization (MPI_PARALLEL or NOT_MPI_PARALLEL)
SET_IF_EMPTY(MPI_OPTION "NOT_MPI_PARALLEL")

if(MPI_OPTION STREQUAL "MPI_PARALLEL")
  find_package(MPI COMPONENTS CXX REQUIRED)
endif()
