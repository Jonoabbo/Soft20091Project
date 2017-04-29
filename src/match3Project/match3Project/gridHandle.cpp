#include "stdafx.h"
#include "GridHandle.h"


GridHandle::GridHandle()
{
	printGrid();
}

void GridHandle::printGrid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << grid[i][j] << " ";
			if (j == 7)
			{
				std::cout << std::endl;
			}
		}
	}
}

void GridHandle::dropDown()
{
	//find column of 0
	//move 0 to the top of the column
	//replace 0 with new numbers

	grid[3][5] = 0;
	grid[3][6] = 0;
	grid[3][7] = 0;

	grid[3][3] = 0;
	grid[4][3] = 0;
	grid[5][3] = 0;
	
	std::vector<int> columnIndexes;
	int columnIndex = 120;

	//debug stuff
	/*
	std::cout << std::endl;
	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;
	std::cout << columnIndex << std::endl;
	*/

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == 0)
			{
				columnIndexes.push_back(j);
			}
		}
	}

	for (int i = 0; i < columnIndexes.size(); i++)
	{
		dropSortAlgorithm(columnIndexes[i]);
	}

	//debug stuff
	/*
	std::cout << std::endl;
	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;
	std::cout << columnIndex << std::endl;
	*/

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == 0)
			{
				grid[i][j] = rand()%5 +1;
			}
		}
	}

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;
}

void GridHandle::dropSortAlgorithm(int index)
{
	for (int i = 0; i < 7; i++)
	{
		for (int i = 0; i < 7; i++)
		{
			if (grid[i][index] != 0)
			{
				if (grid[i + 1][index] == 0)
				{
					grid[i + 1][index] = grid[i][index];
					grid[i][index] = 0;
				}
			}
		}
	}
}

void GridHandle::checkSwapArea()
{

}