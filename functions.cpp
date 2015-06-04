#include "header.h"

int promptUser() {
	string operation;
	int numSelected, exitStatus;

	

	while(true)
	{
		
		cout<<"set> ";
		cin>>operation;

		//execute user entered operation
		if(operation == "add") {
			exitStatus = ADD;
		} else if (operation == "delete") {
			exitStatus = DELETE;
		} else if (operation == "search") {
			exitStatus = SEARCH;
		} else if (operation == "show") {
			exitStatus = SHOW;
		} else if (operation == "quit") {
			exitStatus = QUIT;
			return exitStatus;
		} else {
			//error check user entered operaition
			cout<<endl<<"INVALID OPERATION"<<endl;
			cout<<"please enter one of the following:"<<endl;
			cout<<"add delete search show or quit"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
			continue; 
		}
		
		//error check user entered integer
		if(cin>>numSelected) {
			break;
		} else {
			cout<<endl<<"INVALID NUMBER"<<endl;
			cout<<"please try again"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n') ;
		}
	}
	
	cout<<"You entered "<<operation<<" and "<<numSelected<<endl;

	return exitStatus;
}