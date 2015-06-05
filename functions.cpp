#include "header.h"

int getKey() {
	int numSelected;
	cin>>numSelected;
		if(!(cin<<numSelected)||(numSelected<0))
		 {
			cout<<endl<<"INVALID NUMBER"<<endl;
			cout<<"please try again"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
			numSelected = -1; //error code
		}
	return numSelected;
}

//HASHTABLE FUNCTIONS
void hashTable::addElement(int key) {
	int hash = (key%NUM_BUCKETS);
	element *walk;

	if(table[hash] == NULL) {
		//add a node
		table[hash] = new element(key);
		table[hash]->next = NULL;
	} else {
		//create a walk
		walk = table[hash];
		
		//make sure there isn't a duplicate
		if(walk->getValue() == key) {
			cout<<"WARNING: duplicate input: "<<key<<endl;
			return;
		}		

		//look for new space
		while(walk->next!=NULL) 
		{
			//make sure there isn't a duplicate
			if(walk->getValue() == key) {
				cout<<"WARNING: duplicate input: "<<key<<endl;
				return;
			}
			walk = walk->next; 
		}
		//create new space
		walk->next = new element(key);
		//nullify next
		walk->next->next = NULL;
	}
}

void hashTable::deleteElement(int key) {

}

void hashTable::searchElement(int key) {
	element *walk; 
	for(int i = 0; i < NUM_BUCKETS; i++)
	{
		walk = table[i];

		while(walk != NULL) 
		{
			if(walk->getValue() == key) 
			{
				cout<<"true"<<endl;
				return;
			}
			walk = walk->next;
		}
	}
	cout<<"false"<<endl;
}

void hashTable::showTable() {
	element *walk;

	for ( int i = 0; i < NUM_BUCKETS; i++)
	{
		cout<<"(";

		walk = table[i];
		
		while(walk!=NULL)
		{
			cout<<walk->getValue()<<",";
			walk = walk->next;
		}

		if(i == (NUM_BUCKETS-1))
			cout<<")";
		else
			cout<<")-";
	}
	cout<<endl;
}