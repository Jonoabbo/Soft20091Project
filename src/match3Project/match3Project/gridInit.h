#include <iostream>

class gridInit
{
public:
	int grid[8][8];

	gridInit()
	{
		srand(time(NULL));

		//create grid of random numbers

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				grid[i][j] = (rand() % 5) + 1;
				std::cout << "Position " << i << ", " << j << " : " << grid[i][j] << std::endl;
			}
		}
	}

	//search grid to find 3 4 5 matches
	void searchForMatches();

	//swap two positions
	void swapPositions();
};