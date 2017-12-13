ExternalProject_Add(ec
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/ec
    CONFIGURE_COMMAND sed -i "s/-Werror /-std=gnu90 /g" Makefile.toolchain
    BUILD_COMMAND make
    INSTALL_COMMAND make install
)

ExternalProject_Get_Property(ec install_dir)

add_library(ec STATIC IMPORTED)
include_directories(${install_dir}/ec/include)
