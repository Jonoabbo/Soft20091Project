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

	int matchSize;

	int red= 0;
	int blue = 0;
	int yellow = 0;
	int green = 0;
	int damage = 0;

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
					if (checkedLines[i][j] == 9)
					{
						//ignore this
					}
					else
					{
						std::cout << std::endl;
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
					}
				}

				matchSize = (checkedLines[i].size()-2)/2;
				std::cout << "the size of the match is: " << matchSize << std::endl;

			}
		}

		//call drop down to replace zeros
		dropDown();

		//stores the positions of all matches
		std::vector<int> matchPositions;

		//stores the coords of a matches from each line
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
					//pointless separators can be removed
					matchPositions.erase(matchPositions.begin(), matchPositions.begin() + 1);
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

					//remove coords from vector (removes first two elements)
					matchPositions.erase(matchPositions.begin(), matchPositions.begin() + 1);

				}
			}

			//float zeros to the top and replace
			dropDown();

			//assign all match coords to matchPositions again
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

		}

		//once all matches have been found
		//give player score

		if (playersTurn)
		{
			player.adjustRed(red);
			std::cout << "player gained " << red << " red!" << std::endl;
			player.adjustBlue(blue);
			std::cout << "player gained " << blue << " blue!" << std::endl;
			player.adjustYellow(yellow);
			std::cout << "player gained " << yellow << " yellow!" << std::endl;
			player.adjustGreen(green);
			std::cout << "player gained " << green << " green!" << std::endl;
			enemy.adjustHp(-damage);
		}
		else
		{
			enemy.adjustRed(red);
			enemy.adjustBlue(blue);
			enemy.adjustYellow(yellow);
			enemy.adjustGreen(green);
			player.adjustHp(-damage);
		}

		//set next players turn
		if (playersTurn)
		{
			if (matchSize > 3)
			{
				//stays the same
				playersTurn = true;
			}
			else
			{
				//swaps to enemies turn
				playersTurn = false;
			}
		}
		else
		{
			if (matchSize > 3)
			{
				//stays the same
				playersTurn = false;
			}
			else
			{
				//swaps to enemies turn
				playersTurn = false;
			}
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