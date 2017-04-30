#include <iostream>
#include <vector>
#include <time.h>

class GridInit
{
private:
	//initialises grid
	GridInit();

public:
	int grid[8][8];

	
	//search grid to find 3 4 5 matches
	//int checkForMatch();

	int checkForMatches();

	std::vector<int> findMatchHorizontal(int row);

	std::vector<int> findMatchVertical(int column);


	//OLIVER TO IMPLEMENT -- you handle this part
	void checkForPossibleSwaps();

	
};