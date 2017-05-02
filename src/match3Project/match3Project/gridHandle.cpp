#include "stdafx.h"
#include "GridHandle.h"
#include "SaveFile.h"


GridHandle::GridHandle()
{
	//do nothing
}
GridHandle::GridHandle(playerClass newP, enemyClass newE){
	player = newP;
	enemy = newE;
}
GridHandle::GridHandle(playerClass newP, enemyClass newE, std::string board) {
	player = newP;
	enemy = newE;
	readFromString(board);
}

playerClass GridHandle::getPlayer()
{
	return player;
}

enemyClass GridHandle::getEnemy()
{
	return enemy;
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

	//grid[3][5] = 0;
	//grid[3][6] = 0;
	//grid[3][7] = 0;

	//grid[3][3] = 0;
	//grid[4][3] = 0;
	//grid[5][3] = 0;
	
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

bool GridHandle::checkSwapArea(Move moves)
{
	std::vector<int> checkedLines[3];

	int red;
	int blue;
	int yellow;
	int green;
	int damage;

	if (moves.firstI == moves.secondI)
	{
		//horizontal swap
		std::cout << "Attempting Horizontal Swap" << std::endl;
		checkedLines[0] = findMatchHorizontal(moves.firstI);
		std::cout << checkedLines[0].empty();

		checkedLines[1] = findMatchVertical(moves.firstJ);
		std::cout << checkedLines[1].empty();

		checkedLines[2] = findMatchVertical(moves.secondJ);
		std::cout << checkedLines[2].empty();
	}
	else
	{
		//vertical swap
		std::cout << "Attempting Vertical Swap" << std::endl;
		checkedLines[0] = findMatchVertical(moves.firstJ);
		std::cout << checkedLines[0].empty();
		
		checkedLines[1] = findMatchHorizontal(moves.firstI);
		std::cout << checkedLines[1].empty();

		checkedLines[2] = findMatchHorizontal(moves.secondI);
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
					moves.tile = grid[checkedLines[i][j]][checkedLines[i][j + 1]];
					std::cout << "the value at point: " << checkedLines[i][j] << ", " << checkedLines[i][j + 1] << " is: " << moves.tile << std::endl;

					switch (moves.tile)
					{
					case 1:
						red++;
						break;
					case 2:
						blue++;
						break;
					case 3:
						yellow++; 
						break;
					case 4:
						green++;
						break;
					case 5:
						damage++;
						break;
					}

					grid[checkedLines[i][j]][checkedLines[i][j + 1]] = 0;
					std::cout << "the value at point: " << checkedLines[i][j] << ", " << checkedLines[i][j + 1] << " has been changed to: " << grid[checkedLines[i][j]][checkedLines[i][j + 1]] << std::endl;
					if (checkedLines[i][j] == 9) break;
				}

				moves.size = checkedLines[i].size;
				std::cout << "the size of the match is: " << moves.size << std::endl;

			}
		}

		//call drop down to replace zeros
		dropDown();

		//stores the positions of all matches
		std::vector<int> matchPositions;

		std::vector<int> verticalMatches;
		std::vector<int> horizontalMatches;

		//for each row
		for (int i = 0; i < 8; i++)
		{
			//for each match in the vector returned by the function
			horizontalMatches = findMatchHorizontal(i);
			for (int i = 0; i < horizontalMatches.size(); i++)
			{
				matchPositions.push_back(horizontalMatches[i]);
			}
		}

		horizontalMatches.clear();

		//for each column
		for (int i = 0; i < 8; i++)
		{
			//for each match in the vector returned by the function
			verticalMatches = findMatchVertical(i);
			for (int i = 0; i < verticalMatches.size(); i++)
			{
				matchPositions.push_back(verticalMatches[i]);
			}
		}

		verticalMatches.clear();

		//loop through all positions stored in matchPositions
		//increment 'rewards' counters
		//remove coords from vector
		while (!matchPositions.empty())
		{
			for (int i = 0; i < matchPositions.size(); i+= 2)
			{
				if (matchPositions[i] == 9)
				{
					//ignore these ones
				}
				else
				{
					//increment 'reward'
					int tile = grid[matchPositions[i]][matchPositions[i + 1]];

					switch (tile)
					{
					case 1:
						red++;
						break;
					case 2:
						blue++;
						break;
					case 3:
						yellow++;
						break;
					case 4:
						green++;
						break;
					case 5:
						damage++;
						break;
					}

					//set to zero
					grid[matchPositions[i]][matchPositions[i + 1]] = 0;

					//remove coords from vector
					matchPositions.pop_back

				}
			}

			//float zeros to the top and replace
			dropDown();

		}

	}

}

void GridHandle::swapPositions(Move moves)
{
	//perform swap
	int temp = grid[moves.firstI][moves.firstJ];
	grid[moves.firstI][moves.firstJ] = grid[moves.secondI][moves.secondJ];
	grid[moves.secondI][moves.secondJ] = temp;

	std::cout << std::endl;
	printGrid();
	std::cout << std::endl;

	//call area check
	bool valid = checkSwapArea(moves);

	if (valid)
	{
		//end turn
	}
	else
	{
		std::cout << "Not a valid swap!" << std::endl;

		int temp = grid[moves.firstI][moves.firstJ];
		grid[moves.firstI][moves.firstJ] = grid[moves.secondI][moves.secondJ];
		grid[moves.secondI][moves.secondJ] = temp;

		std::cout << std::endl;
		printGrid();
		std::cout << std::endl;
	}
}

saveFile GridHandle::saveGame(std::string test)
{
	saveFile temp;

	temp.player = player;
	temp.enemy = enemy;
	temp.board = test;

	return temp;
}