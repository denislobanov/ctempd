cmake_minimum_required (VERSION 3.1)
project (ctempd VERSION 0.1.0)

find_package(ectool REQUIRED)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(thirdparty)

