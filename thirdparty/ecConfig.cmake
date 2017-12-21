include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

ExternalProject_Add(ectool
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/ec
    CONFIGURE_COMMAND sed -i "s/-Werror /-std=gnu90 /g" ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/ec/Makefile.toolchain
    BUILD_COMMAND make BOARD=samus -j9
    INSTALL_COMMAND cmake -E echo "Skipping install step."
    BUILD_IN_SOURCE 1
    PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/ec/
)

ExternalProject_Get_Property(ectool source_dir)

set(EC_INCLUDE_DIRS ${source_dir} ${source_dir}/include ${source_dir}/util
                    ${source_dir}/chip/lm4/ ${source_dir}/board/samus
                    ${source_dir}/test)

# create library of external objects
#add_library(ec STATIC ${source_dir}/build/samus/util/
#    ${source_dir}/util/comm-dev
#    ${source_dir}/util/comm-lpc
#    ${source_dir}/util/comm-i2c
#    ${source_dir}/util/misc_util
#    ${source_dir}/util/ectool_keyscan
#    ${source_dir}/util/ec_flash
#    ${source_dir}/util/ec_panicinfo
#    ${source_dir}/util/export_taskinfo)

file(GLOB ec_objs ${source_dir}/build/samus/RW/chim/lm4/*.o 
    ${source_dir}/build/samus/RW/common/*.o
    ${source_dir}/build/samus/RW/core/cortex-m/*.o
    ${source_dir}/build/samus/RW/driver/*.o
    ${source_dir}/build/samus/RW/power/*.o
    ${source_dir}/build/samus/RW/util/export_taskinfo.ro.o)

add_library(ec STATIC ${ec_objs})

#target_include_directories(ec PRIVATE ${EC_INCLUDE_DIRS})
set_target_properties(ec PROPERTIES LINKER_LANGUAGE C EXTERNAL_OBJECT true GENERATED true)

