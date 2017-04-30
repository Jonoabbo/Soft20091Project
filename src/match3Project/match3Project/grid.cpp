#include "stdafx.h"
#include "grid.h"

Grid::Grid()
{
	//hello world!
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

		if (grid[row][j] != grid[row][j + 1])
		{
			if (aCounter == 2) //Match 3 is found
			{
				for (int i = 2; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back(j - i);
				}
				matchPositions.push_back(0);
			}
			else if (aCounter == 3)
			{
				for (int i = 3; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back(j - i);
				}
				matchPositions.push_back(0);
			}
			else if (aCounter == 4)
			{
				for (int i = 4; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back(j - i);
				}
				matchPositions.push_back(0);
			}

			//reset counter
			aCounter = 0;
		}
	}

	return matchPositions;

}

std::vector<int> Grid::findMatchVertical(int column)
{
	int dCounter = 0;
	std::vector<int> matchPositions; //stores 2 ints for each position index form: {i,j} with 0 to separate the 'matches'

	for (int i = 0; i < 8; i++)
	{
		//going across --->
		if (grid[i][column] == grid[i + 1][column])
		{
			dCounter++;
		}

		if (grid[i][column] != grid[i + 1][column])
		{
			if (dCounter == 2) //Match 3 is found
			{
				for (int j = 2; j > 0; j--)
				{
					matchPositions.push_back(j);
					matchPositions.push_back(i - j);
					matchPositions.push_back(0);
				}
			}
			else if (dCounter == 3)
			{
				for (int j = 3; j > 0; j--)
				{
					matchPositions.push_back(j);
					matchPositions.push_back(i -j);
					matchPositions.push_back(0);
				}
			}
			else if (dCounter == 4)
			{
				for (int j = 4; j > 0; j--)
				{
					matchPositions.push_back(j);
					matchPositions.push_back(i- j);
					matchPositions.push_back(0);
				}
			}

			//reset counter
			dCounter = 0;
		}
	}

	return matchPositions;

}
