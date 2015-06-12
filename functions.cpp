#include "header.h"

using namespace std;

//gets var key by reference
//returns if retrieving key was successfull or not
//beautifies main menu
bool getKey(int &key) {
	if(!(cin>>key))
	 {
		cout<<endl<<"Error: INVALID NUMBER"<<endl;
		cout<<"please try again"<<endl<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		return false;
	} else {
		return true;
	}
}

//recieves key, hashes it and places it in correct bucket
//checks for duplicates
void hashTable::addElement(int key) {
	int hash = ((key*key)%NUM_BUCKETS); //hash formula given in requirements
	element *walk; //temp pointer that steps through linked list
	element *chaser; //temp pointer that follows behind walk

	//bucket is empty
	if(!table[hash])
		table[hash] = new element(key);
	else //bucket is not empty, append value
	{
		
		walk = table[hash]; //sets walk to the first element in correct bucket

		do {
			if(walk->getValue() == key)
			{
				cout<<"WARNING: duplicate input: "<<key<<endl;
				return; 	
			}
			chaser = walk;
			walk = walk->next;
		} while(walk);

		chaser->next = new element(key);
	}
}

void hashTable::deleteElement(int key) {
	int hash = ((key*key)%NUM_BUCKETS); //hash formula given in requirements

	element *chaser;
	element *walk;
	
	walk = table[hash];

	while(walk) 
	{
		chaser = walk;
		walk = walk->next;
		
		if(chaser->getValue() == key)
		{
			//DELETE HEAD
			table[hash] = walk; //set tail end of list to beginning of bucket
			delete chaser; //delete the selected element
			return;
		} 
		else if (walk)
		{
			if(walk->getValue() == key)
			{
				//DELETE FROM MIDDLE OF LIST
				if(walk->next) 
				{
					chaser->next = walk->next;
					delete walk;
				}
				else { //delete from end
					chaser->next = NULL;
					delete walk;
				} 

				return;	
			}
		}
	}//end while

	cout<<"WARNING: target value not found: "<<key<<endl;
}

void hashTable::searchElement(int key) {
	element *walk; 
	int hash;

	hash = ((key*key)%NUM_BUCKETS); //finds the bucket that the key is in
	walk = table[hash]; //sets the walk to the first item in the bucket
	
	//loop through every element in selected bucket
	while(walk) 
	{
		if(walk->getValue() == key)
		{
			cout<<"true"<<endl;
			return; //return after finding key
		}
		walk = walk->next;
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
