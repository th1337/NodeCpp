cmake_minimum_required(VERSION 3.4)

project(NodeCpp)

set(LIBRARY_OUTPUT_PATH build)
set(LIB_NAME nodecpp)


#Source files list generation.

file(

        GLOB

        source_files

        src/*

)



#Library declaration

add_library(

        ${LIB_NAME}

        ${source_files}

)
target_compile_features(${LIB_NAME} PRIVATE cxx_range_for)
target_link_libraries(${LIB_NAME} -lfcgi++ -lfcgi)
