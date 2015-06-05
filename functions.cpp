#include "header.h"

using namespace std;

int getKey() {
	int numSelected;
		if(!(cin>>numSelected)||(numSelected<0))
		 {
			cout<<endl<<"Error: INVALID NUMBER"<<endl;
			cout<<"please try again"<<endl<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize> :: max(), '\n');
			numSelected = -1; //error code
		}
	return numSelected;
}

//HASHTABLE FUNCTIONS
void hashTable::addElement(int key) {
	int hash = ((key*key)%NUM_BUCKETS);
	element *walk;

	if(!table[hash]) {
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
		while(walk->next) 
		{
			//make sure there isn't a duplicate
			if(walk->getValue() == key) {
				cout<<"WARNING: duplicate input: "<<key<<endl;
				return;
			}
			walk = walk->next; 
		}

		//make sure there isn't a duplicate
		if(walk->getValue() == key) {
			cout<<"WARNING: duplicate input: "<<key<<endl;
			return;
		}
		
		//create new space
		walk->next = new element(key);
		//nullify next
		walk->next->next = NULL;
	}
}

void hashTable::deleteElement(int key) {
	
	for (int i = 0; i < NUM_BUCKETS; i++) {
		
		element *chaser = table[i];
		
		if(!chaser) 
		{
			continue; //there's nothing in this bucket...
		}

		element *walk = table[i]->next;

		if(chaser->getValue() == key)
		{
			//delete the head
			table[i] = walk;
			delete chaser;
			return;
		}

		while(walk) 
		{
			if(walk->getValue() == key)
			{
				if(!walk->next)
				{
					//at the end of the list
					delete walk;
					chaser->next = NULL;
					return;
				} else {
					//element is in the middle
					chaser->next = walk->next;
					delete walk;
					return;
				}
			}
			//step through the linked list
			chaser = walk;
			walk = walk->next;
		}

	}
	cout<<"WARNING: target value not found: "<<key<<endl;

}

void hashTable::searchElement(int key) {
	element *walk; 
	//loop through every bucket
	for(int i = 0; i < NUM_BUCKETS; i++)
	{
		walk = table[i];
		//loop through every element in each bucket
		while(walk) //
		{
			if(walk->getValue() == key)
			{
				cout<<"true"<<endl;
				return; //return after finding key
			}
			walk = walk->next;
		}
	}
	cout<<"false"<<endl; //key is not found, display false
}

void hashTable::showTable() {
	element *walk;
	//loop through each bucket
	for ( int i = 0; i < NUM_BUCKETS; i++)
	{
		cout<<"(";

		walk = table[i];
		//loop through each element in a bucket
		while(walk)
		{
			if(!walk->next) //do not add a comma at the end of a linked list
				cout<<walk->getValue();
			else
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
