#include "stdafx.h"
#include "grid.h"

Grid::Grid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j];
		}
	}
}

std::string Grid::writeToString()
{
	std::string gridString;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::string temp = std::to_string(grid[i][j]);

			std::cout << grid[i][j] << " " << " To string: " << temp << std::endl;

			gridString.append(std::to_string(grid[i][j]));
		}
	}

	return gridString;

}

std::vector<int> Grid::findMatchHorizontal(int row)
{
	int aCounter = 0;
	std::vector<int> matchPositions; //stores 2 ints for each position index form: {i,j} with 0 to separate the 'matches'

	for (int j = 0; j < 8; j++)
	{
		//going across --->
		if (grid[row][j] == grid[row][j + 1])
		{
			aCounter++;
		}

		if (grid[row][j] == grid[row][j + 1])
		{
			if (aCounter == 2) //Match 3 is found
			{
				for (int i = 2; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back((j + 1) - i);
					matchPositions.push_back(0);
				}
			}
			else if (aCounter == 3)
			{
				for (int i = 3; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back((j + 1) - i);
					matchPositions.push_back(0);
				}
			}
			else if (aCounter == 4)
			{
				for (int i = 4; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back((j + 1) - i);
					matchPositions.push_back(0);
				}
			}

			//reset counter
			aCounter = 0;
			grid[row][j + 1] = rand() % 5 + 1;
			//nMatchesFound++;
		}
	}

	return matchPositions;

}
