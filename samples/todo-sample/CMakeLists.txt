cmake_minimum_required(VERSION 3.4)

project(TodoNodeCpp)

#Génération de la liste des fichiers sources

file(

        GLOB

        source_files

        *

)

include_directories(../../src)

#Déclaration de l'exécutable

add_executable(

        main

        ${source_files}

)
target_compile_features(main PRIVATE cxx_range_for)
target_link_libraries(main -lfcgi++ -lfcgi)
find_library(LIBNODECPP_LIBRARY nodecpp HINT ../../build)
target_link_libraries (main ${LIBNODECPP_LIBRARY})
