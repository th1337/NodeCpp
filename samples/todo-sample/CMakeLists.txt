cmake_minimum_required(VERSION 3.5)

project(TodoNodeCpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_library(LIBNODECPP_LIBRARY nodecpp HINT ../../build)
include_directories(../../src)

set(SOURCE_FILES hellobasicauthauthenticator.h hellobasicauthauthorizator.h hellouser.h todoapplication.cpp todocontroller.cpp todofirewall.cpp hellobasicauthauthenticator.cpp hellobasicauthauthorizator.cpp hellouser.cpp main.cpp todoapplication.h todocontroller.h todofirewall.h)

add_executable(main ${SOURCE_FILES})
target_link_libraries(main ${LIBNODECPP_LIBRARY})
target_link_libraries(main -lfcgi++ -lfcgi)
