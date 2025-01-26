# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\KomunikatorWiad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\KomunikatorWiad_autogen.dir\\ParseCache.txt"
  "KomunikatorWiad_autogen"
  )
endif()
