cmake_minimum_required (VERSION 3.1)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
project (ctempd VERSION 0.1.0)

add_subdirectory(src)
add_subdirectory(thirdparty)

ExternalProject_Get_Property(ec install_dir)

add_library(ec-tool STATIC IMPORTED)
set_property(TARGET ec PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${install_dir})
set_property(TARGET ec PROPERTY IMPORTED_LOCATION ${install_dir}/build/samus)
include_directories(${install_dir}/ec/include ${install_dir}/util)
