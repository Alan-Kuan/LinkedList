#include <iostream>
#include "linked_list.hpp"

using namespace std;

// namespace of my library
using namespace Nlib;

int main(void){

	LinkedList<int> list = {1, 2, 3, 4, 5};

	list[3] = 3;

	cout << list[3] << endl;

	const LinkedList<double> list2 = {0.1, 0.2, 0.3};

	cout << list2[0] << endl;

	return 0;

}
