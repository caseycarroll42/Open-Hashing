/*
Program's additional error checking capabilities:
	will not fail when user enters in a non-existent operation
	will not fail if user enters a non-integer value
	will not fail if user enters in interger value less than 100
*/

#include "header.h"

int main() {
	hashTable table;
	string operation;
	int key;

	while(true)
	{
		cout<<"set> ";
		cin>>operation;

		//execute user entered operation
		if(operation == "add") {
			key = getKey();
			if(key == -1) 
			{
				continue;
			} else {
				table.addElement(key);
			}
		} else if (operation == "delete") {
			key = getKey();
			if(key == -1) 
			{
				continue;
			} else {

				table.deleteElement(key);
			}
		} else if (operation == "search") {
			key = getKey();
			if(key == -1) 
			{
				continue;
			} else {
				table.searchElement(key);
			}
		} else if (operation == "show") {
			table.showTable();
		} else if (operation == "quit") {
			cout<<"terminating program..."<<endl;
			return 0;
		} else {
			//error check user entered operaition
			cout<<endl<<"INVALID OPERATION"<<endl;
			cout<<"please enter one of the following:"<<endl;
			cout<<"add delete search show or quit"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n'); 
		}
	}

	return 0;
}