#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sfml-system" for configuration ""
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-system.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/sfml-system-2.dll"
  )

list(APPEND _cmake_import_check_targets sfml-system )
list(APPEND _cmake_import_check_files_for_sfml-system "${_IMPORT_PREFIX}/lib/libsfml-system.a" "${_IMPORT_PREFIX}/bin/sfml-system-2.dll" )

# Import target "sfml-main" for configuration ""
set_property(TARGET sfml-main APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-main.a"
  )

list(APPEND _cmake_import_check_targets sfml-main )
list(APPEND _cmake_import_check_files_for_sfml-main "${_IMPORT_PREFIX}/lib/libsfml-main.a" )

# Import target "sfml-window" for configuration ""
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-window.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/sfml-window-2.dll"
  )

list(APPEND _cmake_import_check_targets sfml-window )
list(APPEND _cmake_import_check_files_for_sfml-window "${_IMPORT_PREFIX}/lib/libsfml-window.a" "${_IMPORT_PREFIX}/bin/sfml-window-2.dll" )

# Import target "sfml-network" for configuration ""
set_property(TARGET sfml-network APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-network PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-network.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/sfml-network-2.dll"
  )

list(APPEND _cmake_import_check_targets sfml-network )
list(APPEND _cmake_import_check_files_for_sfml-network "${_IMPORT_PREFIX}/lib/libsfml-network.a" "${_IMPORT_PREFIX}/bin/sfml-network-2.dll" )

# Import target "sfml-graphics" for configuration ""
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-graphics.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/sfml-graphics-2.dll"
  )

list(APPEND _cmake_import_check_targets sfml-graphics )
list(APPEND _cmake_import_check_files_for_sfml-graphics "${_IMPORT_PREFIX}/lib/libsfml-graphics.a" "${_IMPORT_PREFIX}/bin/sfml-graphics-2.dll" )

# Import target "sfml-audio" for configuration ""
set_property(TARGET sfml-audio APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(sfml-audio PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-audio.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "OpenAL::OpenAL"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/sfml-audio-2.dll"
  )

list(APPEND _cmake_import_check_targets sfml-audio )
list(APPEND _cmake_import_check_files_for_sfml-audio "${_IMPORT_PREFIX}/lib/libsfml-audio.a" "${_IMPORT_PREFIX}/bin/sfml-audio-2.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
