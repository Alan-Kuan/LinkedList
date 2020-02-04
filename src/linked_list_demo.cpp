#include <iostream>
#include "../include/linked_list.hpp"

using namespace std;

using namespace ll;

namespace Cmd{

	enum {exit, push_front, push_back, insert, update, removeAt, getAt, clear, print};

}

int main(void){

	LinkedList<int> list;

	int cmd, args[2];

	ListNode<int>* getten_node;

	bool terminated = false;

	do{

		cout << "0: exit, 1: push front, 2: push back, 3: insert, 4: update, 5: remove at, 6: get at, 7: clear, 8: print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(1 <= cmd && cmd <= 4){

			cout << "Enter the new data: ";

			cin >> args[0];

		}

		if(3 <= cmd && cmd <= 6){

			cout << "Enter the position: ";

			cin >> args[1];

			if(cmd > 3 && (getten_node = list.getAt(args[1])) == nullptr)
				cout << "Failed: The node at " << args[1] << " was not found!" << endl;

		}

		switch(cmd){

			case Cmd::exit:
				terminated = true;
				break;
			case Cmd::push_front:
				list.push_front(args[0]) ? cout << "Successfully pushed " << args[0] << '.' << endl : cout << "Failed: An error occurred while allocating memory." << endl;
				break;
			case Cmd::push_back:
				list.push_back(args[0]) ? cout << "Successfully pushed " << args[0] << '.' << endl : cout << "Failed: An error occurred while allocating memory." << endl;
				break;
			case Cmd::insert:
				list.insert(args[0], args[1]) ? cout << "Successfully inserted " << args[0] << " at " << args[1] << '.' << endl : cout << "Failed: An error occurred while allocating memory, or the given position was out of bound." << endl;
				break;
			case Cmd::removeAt:
				if(list.remove(getten_node)) cout << "Successfully removed the node at " << args[1] << '.' << endl;
				break;
			case Cmd::getAt:
				if(getten_node != nullptr) cout << "Data of the node at " << args[1] << ": " << getten_node -> getData() << endl;
				break;
			case Cmd::update:
				if(getten_node != nullptr) getten_node -> setData(args[0]);
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
