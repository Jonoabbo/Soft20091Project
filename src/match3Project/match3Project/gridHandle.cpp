#include "stdafx.h"
#include "GridHandle.h"


GridHandle::GridHandle()
{
	//printGrid();
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

void GridHandle::checkSwapArea(int pos1i, int pos1j, int pos2i, int pos2j)
{
	//search both rows
	//search both columns
	//if match
	//replace match with zeros
	//award player mana + score
	//call dropDown()
	//check drops for matches
	//repeate

	//else


}

void GridHandle::swapPositions(int pos1i, int pos1j, int pos2i, int pos2j)
{
	//copy grid to temp array
	//store temp[pos1i][pos1j] in tempVar
	//make temp[pos1i][pos1j] equal to temp[pos2i][pos2j]
	//make temp[pos2i][pos2j] equal to tempVar

	//call checkSwapArea()
	//if true then make grid = temp
	//else tell player move cannot be made

}

void GridHandle::readFromString(std::string r){
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j] = r[count] - '0';
			count++;
		}
	}

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;

}

void GridHandle::checkSwapArea(int pos1i, int pos1j, int pos2i, int pos2j)
{
	std::vector<int> checkedLines[3];

	if (pos1i == pos2i)
	{
		//horizontal swap
		findMatchHorizontal(pos1i);
	}
}