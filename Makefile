CC=g++
CFLAGS=-std=c++11 -W -Wall -fPIC -O0
LDFLAGS=-lfcgi++ -lfcgi
LIB_NAME=libnodecpp
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)


build:
	@mkdir build
	make compile
	$(CC) build/*.o -shared -o build/$(LIB_NAME).so

compile: $(OBJ)

request.o: request.h

response.o: response.h

radixurltree.o: radixurltree.h

application.o: application.h radixurltree.h request.h response.h controller.h errorcontroller.h router.h route.h

route.o: route.h controller.h request.h response.h

router.o: router.h route.h controller.h request.h response.h response.h radixurltree.h errorcontroller.h

controller.o: controller.h request.h response.h

errorcontroller.o: errorcontroller.h controller.h request.h response.h

%.o: %.cpp
	$(CC) -o build/$@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf *.o
	@rm -rf build
	@rm -rf *.so

