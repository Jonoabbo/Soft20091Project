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
	int con = checkForMatch();

	while (con != 0)
	{
		con = checkForMatch();
	}
}

int GridInit::checkForMatch()
{
	//seed random
	srand(time(NULL));

	int nMatchesFound = 0;

	int wildCardBitches = 6;

	std::cout << std::endl;
	std::cout << "-----## MATCHES FOUND ##-----" << std::endl;

	//for loops to handle down searches
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//match 1
			int compare = grid[i][j];

			//match 2
			if (compare == grid[i + 1][j])
			{
				//match 3
				if (compare == grid[i + 2][j] && (i <= 5))
				{
					//match 4
					if (compare == grid[i + 3][j] && (i <= 4))
					{
						//match 5
						if (compare == grid[i + 4][j] && (i <= 3))
						{
							std::cout << "Match 5 found at positions: " << i << "," << j << " " << i + 1 << "," << j << " " << i + 2 << "," << j << " " << i + 3 << "," << j << " " << i + 4 << "," << j << std::endl;
							nMatchesFound++;

							//alternate way of implementing swaps
							int randomPos = (rand() % 5);
							grid[i + randomPos][j] = (rand() % 5 + 1);

							//performs swap of positions
							/*int randomPos = (rand() % 5);
							int temp = grid[i + randomPos][j];
							if (j == 7)
							{
								grid[i + randomPos][j] = grid[i + randomPos][j - 1];
								grid[i + randomPos][j - 1] = temp;
								std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j - 1 << std::endl;
								std::cout << std::endl;
							}
							else
							{
								grid[i + randomPos][j] = grid[i + randomPos][j + 1];
								grid[i + randomPos][j + 1] = temp;
								std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j + 1 << std::endl;
								std::cout << std::endl;
							}*/

						}
						else
						{
							std::cout << "Match 4 found at positions: " << i << "," << j << " " << i + 1 << "," << j << " " << i + 2 << "," << j << " " << i + 3 << "," << j << std::endl;
							nMatchesFound++;

							//alternate way of implementing swaps
							int randomPos = (rand() % 5);
							grid[i + randomPos][j] = (rand() % 5 + 1);

							//performs swap of positions
							/*int randomPos = (rand() % 4);
							int temp = grid[i + randomPos][j];
							if (j == 7)
							{
								grid[i + randomPos][j] = grid[i + randomPos][j - 1];
								grid[i + randomPos][j - 1] = temp;
								std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j - 1 << std::endl;
								std::cout << std::endl;
							}
							else
							{
								grid[i + randomPos][j] = grid[i + randomPos][j + 1];
								grid[i + randomPos][j + 1] = temp;
								std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j + 1 << std::endl;
								std::cout << std::endl;
							}*/


						}
					}
					else
					{
						std::cout << "Match 3 found at positions: " << i << "," << j << " " << i + 1 << "," << j << " " << i + 2 << "," << j << std::endl;
						nMatchesFound++;

						//alternate way of implementing swaps
						int randomPos = (rand() % 5);
						grid[i + randomPos][j] = (rand() % 5 + 1);

						//performs swap of positions
						/*int randomPos = (rand() % 3);
						int temp = grid[i + randomPos][j];
						if (j == 7)
						{
							grid[i + randomPos][j] = grid[i + randomPos][j - 1];
							grid[i + randomPos][j - 1] = temp;
							std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j - 1 << std::endl;
							std::cout << std::endl;
						}
						else
						{
							grid[i + randomPos][j] = grid[i + randomPos][j + 1];
							grid[i + randomPos][j + 1] = temp;
							std::cout << "Position: " << i + randomPos << "," << j << " swapped with: " << i + randomPos << "," << j + 1 << std::endl;
							std::cout << std::endl;
						}*/

					}
				}
			}
		}
	}

	//for loops to handle across searches
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//match 1
			int compare = grid[i][j];

			//match 2
			if (compare == grid[i][j + 1])
			{
				//match 3
				if (compare == grid[i][j + 2] && (j <= 5))
				{
					//match 4
					if (compare == grid[i][j + 3] && (j <= 4))
					{
						//match 5
						if (compare == grid[i][j + 4] && (j <= 3))
						{
							std::cout << "Match 5 found at positions: " << i << "," << j << " " << i << "," << j + 1 << " " << i << "," << j + 2 << " " << i << "," << j + 3 << " " << i << "," << j + 4 << std::endl;
							nMatchesFound++;

							//alternate way of implementing swaps
							int randomPos = (rand() % 5);
							grid[i][j + randomPos] = (rand()%5 + 1);

							//performs swap of positions
							/*int randomPos = (rand() % 5);
							int temp = grid[i][j + randomPos];
							if (i == 7)
							{
								grid[i][j + randomPos] = grid[i - 1][j + randomPos];
								grid[i - 1][j + randomPos] = temp;
								std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i - 1 << "," << j + randomPos << std::endl;
								std::cout << std::endl;
							}
							else
							{
								grid[i][j + randomPos] = grid[i + 1][j + randomPos];
								grid[i + 1][j + randomPos] = temp;
								std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i + 1 << "," << j + randomPos << std::endl;
								std::cout << std::endl;
							}*/
						}
					}
					else
					{
						std::cout << "Match 4 found at positions: " << i << "," << j << " " << i << "," << j + 1 << " " << i << "," << j + 2 << " " << i << "," << j + 3 << std::endl;
						nMatchesFound++;

						//alternate way of implementing swaps
						int randomPos = (rand() % 5);
						grid[i][j + randomPos] = (rand() % 5 + 1);

						//performs swap of positions
						/*int randomPos = (rand() % 4);
						int temp = grid[i][j + randomPos];
						if (i == 7)
						{
							grid[i][j + randomPos] = grid[i - 1][j + randomPos];
							grid[i - 1][j + randomPos] = temp;
							std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i - 1 << "," << j + randomPos << std::endl;
							std::cout << std::endl;
						}
						else
						{
							grid[i][j + randomPos] = grid[i + 1][j + randomPos];
							grid[i + 1][j + randomPos] = temp;
							std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i + 1 << "," << j + randomPos << std::endl;
							std::cout << std::endl;
						}*/
					}
				}
				else
				{
					std::cout << "Match 3 found at positions: " << i << "," << j << " " << i << "," << j + 1 << " " << i << "," << j + 2 << std::endl;
					nMatchesFound++;

					//alternate way of implementing swaps
					int randomPos = (rand() % 5);
					grid[i][j + randomPos] = (rand() % 5 + 1);

					//performs swap of positions
					/*int randomPos = (rand() % 3);
					int temp = grid[i][j + randomPos];
					if (i == 7)
					{
						grid[i][j + randomPos] = grid[i - 1][j + randomPos];
						grid[i - 1][j + randomPos] = temp;
						std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i - 1 << "," << j + randomPos << std::endl;
						std::cout << std::endl;
					}
					else
					{
						grid[i][j + randomPos] = grid[i + 1][j + randomPos];
						grid[i + 1][j + randomPos] = temp;
						std::cout << "Position: " << i << "," << j + randomPos << " swapped with: " << i + 1 << "," << j + randomPos << std::endl;
						std::cout << std::endl;
					}*/
				}
			}
		}
	}

	std::cout << "Total Matches found: " << nMatchesFound << std::endl;

	return nMatchesFound;

}

// example[row][coloum]