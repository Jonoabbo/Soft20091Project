#include "stdafx.h"
#include "GridHandle.h"
#include "SaveFile.h"


GridHandle::GridHandle()
{
	//do nothing
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

bool GridHandle::checkSwapArea(int pos1i, int pos1j, int pos2i, int pos2j)
{
	std::vector<int> checkedLines[3];

	if (pos1i == pos2i)
	{
		//horizontal swap
		std::cout << "Attempting Horizontal Swap" << std::endl;
		checkedLines[0] = findMatchHorizontal(pos1i);
		std::cout << checkedLines[0].empty();

		checkedLines[1] = findMatchVertical(pos1j);
		std::cout << checkedLines[1].empty();

		checkedLines[2] = findMatchVertical(pos2j);
		std::cout << checkedLines[2].empty();
	}
	else
	{
		//vertical swap
		std::cout << "Attempting Vertical Swap" << std::endl;
		checkedLines[0] = findMatchVertical(pos1j);
		std::cout << checkedLines[0].empty();
		checkedLines[1] = findMatchHorizontal(pos1i);
		std::cout << checkedLines[1].empty();
		checkedLines[2] = findMatchHorizontal(pos2i);
		std::cout << checkedLines[2].empty();
	}

	if (checkedLines[0].empty() && checkedLines[1].empty() && checkedLines[2].empty())
	{
		std::cout << "Not a valid swap!" << std::endl;
		return false;
	}
	else
	{
		//this is where the fun happens :/
		std::cout << "You aren't shit at coding" << std::endl;

		for (int i = 0; i < 3; i++)
		{
			if (!checkedLines[i].empty())
			{
				for (int j = 0; j < checkedLines[i].size(); j++)
				{
					std::cout << checkedLines[i][j] << " ";
				}

				for (int j = 0; j < checkedLines[i].size(); j += 2)
				{
					std::cout << "the value at point: " << checkedLines[i][j] << ", " << checkedLines[i][j + 1] << " is: " << grid[checkedLines[i][j]][checkedLines[i][j + 1]] << std::endl;
					if (checkedLines[i][j] == 9) break;
				}

			}
		}
	}

}

void GridHandle::swapPositions(int pos1i, int pos1j, int pos2i, int pos2j, playerClass p, enemyClass e)
{
	//perform swap
	int temp = grid[pos1i][pos1j];
	grid[pos1i][pos1j] = grid[pos2i][pos2j];
	grid[pos2i][pos2j] = temp;

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;

	//call area check
	bool valid = checkSwapArea(pos1i, pos1j, pos2i, pos2j);

	if (valid)
	{
		//end turn
	}
	else
	{
		std::cout << "Not a valid swap!" << std::endl;
	}
}

void GridHandle::incrementResource(int resource, playerClass p, enemyClass e)
{
	//switch (resource)
	//{
	//case 1:
	//	//red
	//	
	//case 2:
	//	//blue
	//case 3:
	//	//yellow
	//case 4:
	//	//green
	//case 5:
	//	//damage
	//}
}

saveFile GridHandle::saveGame(playerClass p, enemyClass e)
{
	saveFile temp;

	temp.player = p;
	temp.enemy = e;
	temp.board = writeToString();

	return temp;
}