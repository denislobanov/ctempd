cmake_minimum_required (VERSION 3.1)
project (ctempd VERSION 0.1.0 LANGUAGES C CXX)

find_package(ec PATHS thirdparty thirdparty/ec NO_DEFAULT_PATH)
#find_library(ec ec thirdparty thirdparty/ec thirdparty/ec/util)

add_subdirectory(src)

