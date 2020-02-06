CC = g++

.PHONY: demo, clean

demo: examples/linked_list_demo.cpp include/linked_list.hpp src/linked_list.tpp
	$(CC) -o run_demo $<

clean:
	-rm *.o
