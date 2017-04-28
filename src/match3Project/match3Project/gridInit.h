#include <iostream>

class gridInit
{
public:
	gridInit(int a[8][8]);

	//search grid to find 3 4 5 matches
	void searchForMatches();

	//swap two positions
	void swapPositions();
};