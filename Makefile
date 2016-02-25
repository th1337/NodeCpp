CC=g++
CFLAGS=-std=c++11 -W -Wall -O0
LDFLAGS=-lfcgi++ -lfcgi
LIB_NAME=libnodecpp
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)


build:
	@mkdir build
	make compile
	@g++ build/*.o -shared -o build/$(LIB_NAME).so

compile:request.o response.o radixurltree.o application.o controller.o errorcontroller.o route.o router.o

request.o: request.h

response.o: response.h

radixurltree.o: radixurltree.h

application.o: application.h

route.o: route.h

router.o: router.h

controller.o: controller.h

errorcontroller.o: errorcontroller.h

%.o: %.cpp
	@$(CC) -o build/$@ -c -fPIC $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf *.o
	@rm -rf build
	@rm -rf *.so

