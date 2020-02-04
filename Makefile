CC = g++

vpath %.hpp  ./include 
vpath %.cpp  ./src
vpath %.a    ./lib

all: liblinked_list.a

liblinked_list.a: linked_list.o 
	ar -rsc $@ $<

linked_list.o: linked_list.cpp linked_list.hpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
