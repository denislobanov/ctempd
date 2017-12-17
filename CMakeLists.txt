cmake_minimum_required (VERSION 3.1)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

project (ctempd VERSION 0.1.0 LANGUAGES C CXX)
add_subdirectory(src)
add_subdirectory(thirdparty)

find_library(ec ec thirdparty thirdparty/ec thirdparty/ec/util)

