#include <iostream>
#include "../include/linked_list.hpp"

using namespace std;

// namespace of my library
using namespace Nlib;

namespace Cmd{

	enum{

		exit,
		push_front,
		push_back,
		insert_at,
		update_at,
		update_data,
		remove_at,
		remove_data,
		get_at,
		clear,
		print

	};

}

int main(void){

	LinkedList<int> list;

	int cmd, data, pos, new_data;

	ListNode<int>* getten_node;

	bool terminated = false;

	do{

		cout << Cmd::exit        << ": exit, ";
		cout << Cmd::push_front  << ": push front, ";
		cout << Cmd::push_back   << ": push back, ";
		cout << Cmd::insert_at   << ": insert at, ";
		cout << Cmd::update_at   << ": update at, ";
		cout << Cmd::update_data << ": update data, ";
		cout << Cmd::remove_at   << ": remove at, ";
		cout << Cmd::remove_data << ": remove data, ";
		cout << Cmd::get_at      << ": get at, ";
		cout << Cmd::clear       << ": clear, ";
		cout << Cmd::print       << ": print" << endl;

		cout << "Enter the command code: ";

		cin >> cmd;

		if(cmd == Cmd::insert_at || cmd == Cmd::update_at || cmd == Cmd::remove_at || cmd == Cmd::get_at){

			cout << "Enter the position: ";

			cin >> pos;

			// insert at has its own error message
			if(cmd != Cmd::insert_at && (getten_node = list.at(pos)) == nullptr)
				cout << "Failed: There's no node at " << pos << '!' << endl;

		}

		if(cmd == Cmd::update_data || cmd == Cmd::remove_data){

			cout << "Enter the data to find: ";

			cin >> data;

			if((getten_node = list.find(data)) == nullptr)
				cout << "Failed: There's no node with data " << data << '.' << endl;

		}

		if(Cmd::push_front <= cmd && cmd <= Cmd::update_data){

			if(cmd == Cmd::push_front || cmd == Cmd::push_back || cmd == Cmd::insert_at || getten_node != nullptr){

				cout << "Enter the new data: ";

				cin >> new_data;

			}
		
		}

		switch(cmd){

			case Cmd::exit:
				terminated = true;
				break;
			case Cmd::push_front:
				list.push_front(new_data) ? cout << "Successfully pushed " << new_data << '.' << endl : cout << "Failed: An error occurred while allocating memory." << endl;
				break;
			case Cmd::push_back:
				list.push_back(new_data) ? cout << "Successfully pushed " << new_data << '.' << endl : cout << "Failed: An error occurred while allocating memory." << endl;
				break;
			case Cmd::insert_at:
				list.insert(new_data, pos) ? cout << "Successfully inserted " << new_data << " at " << pos << '.' << endl : cout << "Failed: An error occurred while allocating memory, or the given position was out of bound." << endl;
				break;
			case Cmd::update_at:
			case Cmd::update_data:
				if(getten_node == nullptr) break;
				getten_node -> setData(new_data);
				cout << "Successfully updated." << endl;
				break;
			case Cmd::remove_at:
			case Cmd::remove_data:
				if(list.remove(getten_node)) cout << "Successfully removed." << endl;
				break;
			case Cmd::get_at:
				if(getten_node != nullptr) cout << "Data of the node at " << pos << ": " << getten_node -> getData() << endl;
				break;
			case Cmd::clear:
				list.clear();
				cout << "Successfully cleared the list." << endl;
				break;
			case Cmd::print:
				cout << "size: " << list.size() << endl;
				list.print();
				break;
			default:
				cout << "Wrong command!" << endl;

		}

	}while(!terminated);

	return 0;

}
