#include "header.h"

int main() {

	switch(promptUser())
	{
		case ADD:
			break;
		case DELETE:
			break;
		case SEARCH:
			break;
		case SHOW:
			break;
		case QUIT:
			cout<<"program terminating..."<<endl;
			return 0;
		default:
			cout<<"An error occured..."<<endl;
	}

	return 0;
}