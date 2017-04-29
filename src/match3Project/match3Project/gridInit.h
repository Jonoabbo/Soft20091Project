#include <iostream>
#include <time.h>

class GridInit
{
public:
	int grid[8][8];

	//initialises grid
	GridInit();

	//search grid to find 3 4 5 matches
	int checkForMatch();

	//OLIVER TO IMPLEMENT -- you handle this part
	void checkForPossibleSwaps();

	
};