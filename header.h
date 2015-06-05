//imports
#include <iostream>
#include <limits>

const int NUM_BUCKETS = 7;

//namespace 
using namespace std;

//functions
int getKey();

//CLASSES
class element {
	int value;
public:
	element *next;

	element(){}
	element(int inputValue) 
	{
		value = inputValue;
	}

	int getValue(){return value;}

	void setValue(int x){cout<<"overwriting with "<<x<<endl; value = x;}
};

class hashTable {
	element **table;
public:
	hashTable(){
		//initialize table
		table = new element*[NUM_BUCKETS];
		for (int i = 0; i<NUM_BUCKETS; i++) 
		{
			table[i] = NULL;
		}
	}; 
	
	void addElement(int key);
	void deleteElement(int key);
	void searchElement(int key);
	void showTable();
};