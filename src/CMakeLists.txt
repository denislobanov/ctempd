set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB ctempd_src
    "*.h"
    "*.cpp"
)
add_executable(ctempd ${ctempd_src})
target_link_libraries(ctempd ec)

