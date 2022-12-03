cmake_minimum_required(VERSION 3.13.4)

project(lvcc
  VERSION "0.0.1"
  DESCRIPTION "LabIEW C/C++ library"
  LANGUAGES C CXX)

set(NAMESPACE lvcc)

##
## CMake module paths
##

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

##
## Compile support
##

# Export compile database for IDEs, needed for QtCreator
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

##
## Import functions
##

include(setup_ide_folders)
include(get_standard_library_name)

# Check for name of standard library, use by common
include(CheckCXXSourceCompiles)
get_standard_library_name(STANDARD_LIBRARY)

##
## Targets/Sources
##

add_subdirectory(lvcc)

##
## Compile options
##

# Set the default build type if none specified by user
include(BuildType)
