#include <iostream>
#include <time.h>

class GridInit
{
public:
	int grid[8][8];

	//initialises grid
	GridInit();

	//search grid to find 3 4 5 matches
	void checkForMatch();

	//swap two positions
	void swapPositions();

	//drop down tiles -- performs 'bubble sort'
	void dropDown();

	//OLIVER TO IMPLEMENT -- you handle this part
	void checkForPossibleSwaps();
};