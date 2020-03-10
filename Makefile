CXX = g++

CXXFLAGS = -I include/

.PHONY: demo demo2 clean

demo: examples/linked_list_demo.cpp
	$(CXX) -o run_demo $< $(CXXFLAGS)

demo2: examples/linked_list_demo2.cpp
	$(CXX) -o run_demo2 $< $(CXXFLAGS)

clean:
	-rm *.o
	-rm run_demo*
