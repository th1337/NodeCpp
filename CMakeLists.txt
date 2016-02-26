cmake_minimum_required(VERSION 3.4)

project(NodeCpp)

set(LIBRARY_OUTPUT_PATH build)

#Génération de la liste des fichiers sources

file(

        GLOB

        source_files

        *

)



#Déclaration de l'exécutable

add_library(

        nodecpp

        ${source_files}

)
target_compile_features(nodecpp PRIVATE cxx_range_for)
target_link_libraries(nodecpp -lfcgi++ -lfcgi)
