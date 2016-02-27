cmake_minimum_required(VERSION 3.4)

project(NodeCpp)

set(LIBRARY_OUTPUT_PATH build)

#Source files list generation.

file(

        GLOB

        source_files

        *

)



#Executable declaration

add_library(

        nodecpp

        ${source_files}

)
target_compile_features(nodecpp PRIVATE cxx_range_for)
target_link_libraries(nodecpp -lfcgi++ -lfcgi)
