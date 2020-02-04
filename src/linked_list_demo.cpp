#include <iostream>
#include "../include/linked_list.hpp"

using namespace std;

namespace Cmd{

	enum {exit, push_front, push_back, insert, remove, getAt, update, clear, print};

}

int main(void){

	LinkedList<int> list;

	int cmd, args[2];

	ListNode<int>* getten_node;

	bool terminated = false;

	do{

		cout << "0: exit, 1: push front, 2: push back, 3: insert, 4: remove, 5: get at, 6: update, 7: clear, 8: print" << endl;

		cin >> cmd;

		if(1 <= cmd && cmd <= 3){

			cout << "Enter the data: ";

			cin >> args[0];

		}

		if(3 <= cmd && cmd <= 5){

			cout << "Enter the position: ";

			cin >> args[1];

		}

		if(4 <= cmd && cmd <= 5){

			getten_node = list.getAt(args[1]);

		}

		switch(cmd){

			case Cmd::exit:
				terminated = true;
				break;
			case Cmd::push_front:
				list.push_front(args[0]);
				break;
			case Cmd::push_back:
				list.push_back(args[0]);
				break;
			case Cmd::insert:
				list.insert(args[0], args[1]);
				break;
			case Cmd::remove:
				list.remove(getten_node);
				break;
			case Cmd::getAt:
				cout << "Data of the node at " << args[1] << ": " << getten_node -> getData() << endl;
				break;
			case Cmd::update:
				getten_node -> setData(args[0]);
				break;
			case Cmd::clear:
				list.clear();
				break;
			case Cmd::print:
				list.print();
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(!terminated);

	return 0;

}
