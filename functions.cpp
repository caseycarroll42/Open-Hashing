#include "header.h"

using namespace std;

int getKey() {
	int numSelected;
		if(!(cin>>numSelected))
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
	element *chaser;
	element *walk;


	//bucket is empty
	if(!table[hash])
		table[hash] = new element(key);
	else //bucket is not empty, append value
	{
		walk = table[hash];
		if(walk->getValue() == key)
			{
				cout<<"WARNING: duplicate input: "<<key<<endl;
				return; 
			}
		while(walk->next) {
			if(walk->getValue() == key)
			{
				cout<<"WARNING: duplicate input: "<<key<<endl;
				return; 
			}
			walk = walk->next;
		}
		walk->next = new element(key);
		//walk->next->next = NULL;
		return;
	}
}

void hashTable::deleteElement(int key) {
	element *chaser;
	element *walk;
	
	for (int i = 0; i < NUM_BUCKETS; i++) 
	{
		walk = table[i];

		while(walk) 
		{
			chaser = walk;
			walk = walk->next;
			
			if(chaser->getValue() == key)
			{
				//delete head
				table[i] = walk;
				delete chaser;
				return;
			} 
			else if (walk)
			{
				if(walk->getValue() == key)
				{
					if(walk->next) //delete from middle
						chaser->next = walk->next; 
					else //delete end 
						chaser->next = NULL;
					delete walk;
					return;	
				}
			}
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
