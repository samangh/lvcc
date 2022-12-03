set(TARGET "lvcc")

find_package(LabVIEW REQUIRED)

##
## Source files
##

add_library(${TARGET} INTERFACE)

##
## Includes
##

target_include_directories(${TARGET}
  INTERFACE
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>)

target_link_libraries(${TARGET}
  INTERFACE
   LabVIEW
   $<$<CXX_COMPILER_ID:MSVC>:-SAFESEH:NO>
   "$<$<BOOL:${APPLE}>:-framework CoreFoundation>"
	)

# The LabVIEW Windows libraries have SAFESEH disabled, so to link we have to do the same
if(MSVC)
	target_link_options(${TARGET} PUBLIC "/SAFESEH:NO")
endif()

# include (GenerateExportHeader)
# generate_export_header(${TARGET}
#   EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/include/${PROJECT_NAME}/export/${TARGET}.h")

# setup_ide_folders(TARGET ${TARGET} DIR ${CMAKE_CURRENT_SOURCE_DIR})

##
## Compiler flags
##

target_compile_features(${TARGET} INTERFACE cxx_std_17)

##
## Version
##

configure_file (
  "${PROJECT_SOURCE_DIR}/cmake/version.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.h"
  )

