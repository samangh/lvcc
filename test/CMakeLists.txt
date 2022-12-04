set(TARGET "test")

##
## Source files
##

file(GLOB_RECURSE SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# This MUST be a shared library, as otherwise you can't export from it
# See https://devblogs.microsoft.com/oldnewthing/20140321-00/?p=1433
add_library(${TARGET} SHARED ${SRC_FILES})

##
## Includes
##

target_include_directories(${TARGET}
  INTERFACE
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
  PRIVATE)

target_link_libraries(${TARGET}
  INTERFACE
  PUBLIC
  PRIVATE
   )

include (GenerateExportHeader)
generate_export_header(${TARGET}
  EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/include/${PROJECT_NAME}/export/${TARGET}.h")

set_target_properties(${TARGET} PROPERTIES
  FRAMEWORK TRUE
  VERSION ${PROJECT_VERSION}
  SOVERSION  ${PROJECT_VERSION})

#setup_ide_folders(TARGET ${TARGET} DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  target_compile_definitions(${TARGET} PUBLIC X64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  target_compile_definitions(${TARGET} PUBLIC X86)
endif()


##
## Compiler flags
##

target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_compile_options(${TARGET}
    PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall>
     $<$<CXX_COMPILER_ID:MSVC>:/W4>)

##
## Version
##

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/version.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.h")


