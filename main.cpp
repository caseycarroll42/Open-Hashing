/*
Program's additional error checking capabilities:
	will not fail when user enters in a non-existent operation
	will not fail if user enters a non-integer value
	will not fail if user enters in interger value less than 0
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
			
			if(getKey(key)) {
				table.addElement(key);
			}

		} else if (operation == "delete") {
			
			if(getKey(key)) {
				table.deleteElement(key);
			}
			

		} else if (operation == "search") {
			
			if(getKey(key)) {
				table.searchElement(key);				
			}

		} else if(operation == "show") {
			
			table.showTable();

			//FLUSH BUFFER IN CASE USER ENTERS EXTRA ARGUMENTS 
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');

		} else if (operation == "quit") {
			cout<<"terminating program..."<<endl;
			return 0;
		} else {
			//error check user entered operaition
			cout<<endl<<"INVALID OPERATION"<<endl;
			cout<<"please enter one of the following:"<<endl;
			cout<<"add delete search show or quit"<<endl<<endl;

			//FLUSH BUFFER IN CASE USER ENTERS EXTRA ARGUMENTS 
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		}
	}
	return 0; 
}