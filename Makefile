CC = g++

.PHONY: demo, demo2, clean

demo: examples/linked_list_demo.cpp include/linked_list.hpp src/linked_list.tpp
	$(CC) -o run_demo $<

demo2: examples/linked_list_demo2.cpp include/linked_list.hpp src/linked_list.tpp
	$(CC) -o run_demo2 $<

clean:
	-rm *.o
	-rm run_demo*
