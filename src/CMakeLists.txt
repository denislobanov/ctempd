cmake_minimum_required (VERSION 2.6)
project (ctempd)
file(GLOB ctempd_src
    "*.h"
    "*.cpp"
)
add_executable(ctempd ${ctempd_src})
