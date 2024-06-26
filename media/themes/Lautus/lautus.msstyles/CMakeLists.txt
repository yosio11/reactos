
if(DLL_EXPORT_VERSION GREATER_EQUAL 0x600)
    add_definitions(-DUSE_PNG_IMAGES)
endif()

list(APPEND TEXTFILES
    textfiles/ExtraLargeNormal.INI
    textfiles/LargeFontsNormal.INI
    textfiles/NormalNormal.INI)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/textfiles)
foreach(_file ${TEXTFILES})
    get_filename_component(_file_name ${_file} NAME_WE)
    get_filename_component(_subdir ${_file} DIRECTORY)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_subdir})
    set(_converted_file ${CMAKE_CURRENT_BINARY_DIR}/${_subdir}/${_file_name}_utf16.INI)
    utf16le_convert(${CMAKE_CURRENT_SOURCE_DIR}/${_file} ${_converted_file})
    list(APPEND _converted_files ${_converted_file})
endforeach()

set_source_files_properties(lautus.rc PROPERTIES OBJECT_DEPENDS "${_converted_files}")
add_library(lautus.msstyles MODULE lautus.rc)
set_module_type(lautus.msstyles module)
set_target_properties(lautus.msstyles PROPERTIES SUFFIX "")
add_cd_file(TARGET lautus.msstyles DESTINATION reactos/Resources/Themes/Lautus FOR all)
