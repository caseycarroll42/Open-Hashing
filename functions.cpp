#include "header.h"

void promptUser() {
	string operation;
	int numSelected;

	

	while(true)
	{
		
		cout<<"set> ";
		cin>>operation;

		if(operation == "add") {

		} else if (operation == "delete") {
			
		} else if (operation == "search") {
			
		} else if (operation == "show") {
			
		} else if (operation == "quit") {
			
		} else {
			cout<<endl<<"INVALID OPERATION"<<endl;
			cout<<"please enter one of the following:"<<endl;
			cout<<"add delete search show or quit"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
			continue; 
		}


		
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
}