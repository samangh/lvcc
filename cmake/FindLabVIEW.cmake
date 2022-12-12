# Use 32-bit visa in x86 and 64-bit in x64 by looking at pointer size
# macOS and Linux only use have 64-bit LabVIEW
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(LABVIEW_HINTS
    # MacOS
    "/Applications/National\ Instruments/LabVIEW\ 2018\ 64-bit/cintools/Mach-O"
    "/Applications/National\ Instruments/LabVIEW\ 2019\ 64-bit/cintools/Mach-O"
    "/Applications/National\ Instruments/LabVIEW\ 2020\ 64-bit/cintools/Mach-O"
    "/Applications/National\ Instruments/LabVIEW\ 2021\ 64-bit/cintools/Mach-O"
    "/Applications/National\ Instruments/LabVIEW\ 2022\ 64-bit/cintools/Mach-O"
    "/Applications/National\ Instruments/LabVIEW\ 2018\ 64-bit/cintools"
    "/Applications/National\ Instruments/LabVIEW\ 2019\ 64-bit/cintools"
    "/Applications/National\ Instruments/LabVIEW\ 2020\ 64-bit/cintools"
    "/Applications/National\ Instruments/LabVIEW\ 2021\ 64-bit/cintools"
    "/Applications/National\ Instruments/LabVIEW\ 2022\ 64-bit/cintools"
    #Linux
    "/usr/local/natinst/LabVIEW-2018-64/cintools"
    "/usr/local/natinst/LabVIEW-2019-64/cintools"
    "/usr/local/natinst/LabVIEW-2020-64/cintools"
    "/usr/local/natinst/LabVIEW-2021-64/cintools"
    "/usr/local/natinst/LabVIEW-2022-64/cintools"
    #Windows
    "C:\\Program Files\\National Instruments\\LabVIEW 2018\\cintools"
    "C:\\Program Files\\National Instruments\\LabVIEW 2019\\cintools"
    "C:\\Program Files\\National Instruments\\LabVIEW 2020\\cintools"
    "C:\\Program Files\\National Instruments\\LabVIEW 2021\\cintools"
    "C:\\Program Files\\National Instruments\\LabVIEW 2022\\cintools")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(LABVIEW_HINTS
    "C:\\Program Files (x86)\\National Instruments\\LabVIEW 2018\\cintools"
    "C:\\Program Files (x86)\\National Instruments\\LabVIEW 2019\\cintools"
    "C:\\Program Files (x86)\\National Instruments\\LabVIEW 2020\\cintools"
    "C:\\Program Files (x86)\\National Instruments\\LabVIEW 2021\\cintools"
    "C:\\Program Files (x86)\\National Instruments\\LabVIEW 2022\\cintools")
endif()


find_path(LabVIEW_INCLUDE_DIRS
   NAMES extcode.h
   HINTS ${LabVIEW_DIR} ${LabVIEW_DIR}/cintools ${LabVIEW_DIR}/include ${LABVIEW_HINTS})

find_library(LabVIEW_LIBRARIES
  NAMES lv labviewv
  HINTS ${LabVIEW_DIR} ${LabVIEW_DIR}/cintools ${LabVIEW_DIR}/lib ${LABVIEW_HINTS} ${LABVIEW_HINTS})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LabVIEW DEFAULT_MSG LabVIEW_LIBRARIES LabVIEW_INCLUDE_DIRS)

if(LabVIEW_FOUND AND NOT TARGET LabVIEW)
  add_library(LabVIEW UNKNOWN IMPORTED)
  set_target_properties(LabVIEW PROPERTIES
	IMPORTED_LINK_INTERFACE_LANGUAGES "C"
	IMPORTED_LOCATION "${LabVIEW_LIBRARIES}"
	INTERFACE_INCLUDE_DIRECTORIES "${LabVIEW_INCLUDE_DIRS}")
endif()
