cmake_minimum_required(VERSION 3.5)

project(NodeCpp)

set(LIB_NAME nodecpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_FILES src/anonymoususer.h src/authenticator.cpp src/basicauthcontroller.cpp src/basicauthenticator.h src/errorcontroller.cpp src/nodeauthenticator.cpp src/radixurltree.h src/response.cpp src/route.h src/tokengenerator.cpp src/tools.h src/application.cpp src/authenticator.h src/basicauthcontroller.h src/controller.cpp src/errorcontroller.h src/nodeauthenticator.h src/request.cpp src/response.h src/router.cpp src/tokengenerator.h src/user.h src/application.h src/authorizator.h src/basicauthenticator.cpp src/controller.h src/firewall.h src/radixurltree.cpp src/request.h src/route.cpp src/router.h src/tools.cpp)

add_library(${LIB_NAME} ${SOURCE_FILES})
target_link_libraries(${LIB_NAME} -lfcgi++ -lfcgi)
