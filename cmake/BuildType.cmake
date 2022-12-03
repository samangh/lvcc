# Taken from https://blog.kitware.com/cmake-and-the-default-build-type/,
# by Marcus D. Hanwell

# Modify by S. Ghannadzadeh

# Set a default build type if none was specified
set(default_build_type "Release")

if(CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Using a multi-config generator, please set the Debug/Release mode on your IDE")
else()
  if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
  endif()

  # Capitalise to make string comparisons earlier elsewhere
  string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
  message(STATUS "Build type is '${CMAKE_BUILD_TYPE}'.")
endif()
