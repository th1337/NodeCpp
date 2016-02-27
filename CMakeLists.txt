cmake_minimum_required(VERSION 3.4)

project(NodeCpp)

set(LIBRARY_OUTPUT_PATH build)
set(LIB_NAME nodecpp)
#Génération de la liste des fichiers sources

file(

        GLOB

        source_files

        src/*

)



#Déclaration de l'exécutable

add_library(

        ${LIB_NAME}

        ${source_files}

)
target_compile_features(${LIB_NAME} PRIVATE cxx_range_for)
target_link_libraries(${LIB_NAME} -lfcgi++ -lfcgi)
