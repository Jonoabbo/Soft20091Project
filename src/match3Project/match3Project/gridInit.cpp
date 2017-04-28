#include "stdafx.h"
#include "gridInit.h"

GridInit::GridInit()
{

    //seed random
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

	//check grid for existing matches
	checkForMatch();

}

void GridInit::checkForMatch()
{
	//not here
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int compare = grid[i][j];

			if (compare == grid[i + 1][j])
			{
				if (compare == grid[i + 2][j])
				{
					std::cout << "Match 3 found at positions: " << i << "," << j << " " << i + 1 << "," << j << i + 2 << "," << j << std::endl;
					//swapPositions(rand of three, rand of three below)

					if (compare == grid[i + 3][j] && (i <= 4))
					{
						std::cout << "Match 4 found at positions" << i << "," << j << i + 1 << "," << j << i + 2 << "," << j << i + 3 << "," << j << std::endl;

						if (compare == grid[i + 4][j] && (i <= 3))
						{
							std::cout << "Match 5 found at positions" << i << "," << j << i + 1 << "," << j << i + 2 << "," << j << i + 3 << "," << j << i + 4 << "," << j << std::endl;
						}
					}
				}
			}

		}
	}
}

// example[row][coloum]