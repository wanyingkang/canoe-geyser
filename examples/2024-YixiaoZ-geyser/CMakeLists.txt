# 1. Compile
setup_problem(geyser)

# 4. Copy input files to run directory
file(GLOB inputs *.inp *.yaml)
foreach(input ${inputs})
  execute_process(COMMAND ln -sf ${input} ${CMAKE_BINARY_DIR}/bin/${inp})
endforeach()
