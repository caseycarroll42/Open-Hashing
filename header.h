//imports
#include <iostream>
#include <limits>

//number of buckets in hash table
const int NUM_BUCKETS = 7;

//namespace 
using namespace std;

//functions
int getKey();

//CLASSES

/*
*an element contains an interger value
*an element exists within a bucket of the hashtable
*/
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
};

/*
*hashTable is a collection class
*contains buckets which hold elements
*/
class hashTable {
	element **table;
public:
	hashTable(){
		//initialize table
		//table dynamically created with 7 buckets
		table = new element*[NUM_BUCKETS];
		for (int i = 0; i<NUM_BUCKETS; i++) 
		{
			table[i] = NULL;
		}
	}
	
	//adds and element to a bucket in the table
	void addElement(int key);

	//deletes an element from the table
	void deleteElement(int key);
	//searches for an element in the table and returns boolean response
	void searchElement(int key);
	//prints out the hashTable
	void showTable();
};