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

		if(operation == "show") 
		{
			//FLUSH BUFFER IN CASE USER ENTERS EXTRA ARGUMENTS 
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
			
			table.showTable();
			continue;
		} else if (operation == "quit") {
			cout<<"terminating program..."<<endl;
			return 0;
		}

		if(!(cin>>key))
		 {
			cout<<endl<<"Error: INVALID NUMBER"<<endl;
			cout<<"please try again"<<endl<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize> :: max(), '\n');
			continue;
		}

		//FLUSH BUFFER IN CASE USER ENTERS TWO INTEGER VALUES 
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');

		//execute user entered operation
		if(operation == "add") {
			table.addElement(key);
			
		} else if (operation == "delete") {
			table.deleteElement(key);
		} else if (operation == "search") {
				table.searchElement(key);
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