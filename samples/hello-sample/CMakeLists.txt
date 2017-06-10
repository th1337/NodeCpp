cmake_minimum_required(VERSION 3.5)

project(HelloWorldNodeCpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_library(LIBNODECPP_LIBRARY nodecpp HINT ../../build)
include_directories(../../src)

set(SOURCE_FILES customuser.h hellobasicauthauthenticator.h hellobasicauthcontroller.h hellouser.h securitycontroller.cpp customauthorizator.cpp helloapplication.cpp hellobasicauthauthorizator.cpp hellocontroller.cpp inmemoryauthenticator.cpp securitycontroller.h customauthorizator.h helloapplication.h hellobasicauthauthorizator.h hellocontroller.h inmemoryauthenticator.h sortcontroller.cpp customuser.cpp hellobasicauthauthenticator.cpp hellobasicauthcontroller.cpp hellouser.cpp main.cpp sortcontroller.h)

add_executable(main ${SOURCE_FILES})
target_link_libraries(main ${LIBNODECPP_LIBRARY})
target_link_libraries(main -lfcgi++ -lfcgi)
