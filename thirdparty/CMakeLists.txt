ExternalProject_Add(project_ec
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ec
    CONFIGURE_COMMAND sed -i "s/-Werror /-std=gnu90 /g" ${CMAKE_CURRENT_SOURCE_DIR}/ec/Makefile.toolchain
    BUILD_IN_SOURCE 1
    BUILD_COMMAND make BOARD=samus
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    PREFIX=${CMAKE_CURRENT_BINARY_DIR}/ec
)

ExternalProject_Get_Property(project_ec install_dir)

add_library(ec STATIC IMPORTED)
set_target_properties(ec PROPERTIES IMPORTED_LOCATION ${install_dir}/build/samus)
#set_target_properties(TARGET ec PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${install_dir})
add_dependencies(ec project_ec)

include_directories(${install_dir}/ec/include ${install_dir}/util)
link_directories(${install_dir}/util)

