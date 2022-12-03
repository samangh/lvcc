function(setup_ide_folders)
  set(options "")
  set(multiValueArgs "")
  set(oneValueArgs TARGET DIR)
  cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  file(RELATIVE_PATH rel ${PROJECT_SOURCE_DIR} ${ARG_DIR})
  get_filename_component(PARENT_DIR ${rel} DIRECTORY)
  set_target_properties(${ARG_TARGET} PROPERTIES FOLDER ${PARENT_DIR})
endfunction()
