CC = g++

vpath %.hpp  ./include 
vpath %.cpp  ./src

all: ./lib/liblinked_list.a

./lib/liblinked_list.a: linked_list.o 
	ar -rsc $@ $<

linked_list.o: linked_list.cpp linked_list.hpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	-rm *.o
