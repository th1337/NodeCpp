CC=g++
CFLAGS=-std=c++11 -W -Wall -O0
LDFLAGS=-lfcgi++ -lfcgi
EXEC=main
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf *.o