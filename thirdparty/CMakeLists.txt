ExternalProject_Add(ectool
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ec
    CONFIGURE_COMMAND sed -i "s/-Werror /-std=gnu90 /g" ${CMAKE_CURRENT_SOURCE_DIR}/ec/Makefile.toolchain
    BUILD_COMMAND make BOARD=samus
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    BUILD_IN_SOURCE 1
)

ExternalProject_Get_Property(ectool source_dir)

add_library(ec STATIC ${source_dir}/util/ ${source_dir}/include/ ${source_dir}/board/samus/)
set_target_properties(ec PROPERTIES LINKER_LANGUAGE C)

include_directories(${source_dir}/include ${source_dir}/util)

