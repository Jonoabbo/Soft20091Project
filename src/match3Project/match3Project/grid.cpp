#include "stdafx.h"
#include "grid.h"

using namespace std;
Grid::Grid()
{
	//hello world!
}

string Grid::writeToString()
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

vector<int> Grid::findMatchHorizontal(int row)
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
			for (int i = 0; i < 3; i++)
			{
				matchPositions.push_back(row);
				matchPositions.push_back(j - i);
			}
			matchPositions.push_back(9);
			matchPositions.push_back(9);
		}
		else if (aCounter == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				matchPositions.push_back(row);
				matchPositions.push_back(j - i);
			}
			matchPositions.push_back(9);
			matchPositions.push_back(9);
		}
		else if (aCounter == 4)
		{
			for (int i = 0; i < 5; i++)
			{
				matchPositions.push_back(row);
				matchPositions.push_back(j - i);
			}
			matchPositions.push_back(9);
			matchPositions.push_back(9);
		}

		//reset counter
		aCounter = 0;
		}
	}

	return matchPositions;

}

vector<int> Grid::findMatchVertical(int column)
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
				for (int j = 0; j < 3; j++)
				{
					matchPositions.push_back(i - j);
					matchPositions.push_back(column);
				}
				matchPositions.push_back(9);
				matchPositions.push_back(9);
			}
			else if (dCounter == 3)
			{
				for (int j = 0; j < 4; j++)
				{
					matchPositions.push_back(i - j);
					matchPositions.push_back(column);
				}
				matchPositions.push_back(9);
				matchPositions.push_back(9);
			}
			else if (dCounter == 4)
			{
				for (int j = 0; j < 5; j++)
				{
					matchPositions.push_back(i - j);
					matchPositions.push_back(column);
				}
				matchPositions.push_back(9);
				matchPositions.push_back(9);
			}
			//reset counter
			dCounter = 0;
		}
	}

	return matchPositions;

}

vector<Move> Grid::getMoves() {
	vector<Move> moves, temp;
	moves = getHorizontalMoves(moves);
	temp = getVerticalMoves(moves);
	for (int i = 0; i < temp.size(); i++)
	{
		moves.push_back(temp[i]);			
	}

	return moves;
}

vector<Move> Grid::getHorizontalMoves(vector<Move> moves) {
	Move temp;
	int tile, tempGrid[10][10] = { 0 };
	//reading grid into slightly larger grid with a buffer of -1's around it to allow for easy comparison
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			tempGrid[i][j] == grid[i - 1][j - 1];
		}
	}
	for (int j = 1; j < 8; j++)
	{
		for (int i = 1; i < 8; i++)
		{
			temp.firstI = 0;
			temp.firstJ = 0;
			temp.secondI = 0;
			temp.secondJ = 0;
			temp.tile = 0;
			temp.size = 0;
			tile = tempGrid[i][j];
			//for every co-ordinate in the grid
			if (tile == tempGrid[i + 1][j] || tempGrid[i][j] == tempGrid[i + 2][j])
			{
				if (tile == tempGrid[i + 2][j])
				{
					if (tile == tempGrid[i + 1][j - 1])
					{
						temp.firstI = i;
						temp.firstJ = j;
						temp.secondI = i + 1;
						temp.secondJ = j - 1;
						temp.tile = tile;

						if (tile == tempGrid[i + 3][j])
						{
							temp.size = 4;

						}
						else if (tile == tempGrid[i - 1][j])
						{
							temp.size = 4;
						}
						else
						{
							temp.size = 3;
						}
					}
					else if (tile == tempGrid[i + 1][j + 1])
					{
						temp.firstI = i;
						temp.firstJ = j;
						temp.secondI = i + 1;
						temp.secondJ = j + 1;
						temp.tile = tile;

						if (tile == tempGrid[i + 3][j])
						{
							temp.size = 4;
						}
						else if (tile == tempGrid[i - 1][j])
						{
							temp.size = 4;
						}
						else
						{
							temp.size = 3;
						}
					}///
					else
					{
						if (tile == tempGrid[i + 2][j - 1])//x10/x20/x03
						{
							temp.firstI = i;
							temp.firstJ = j;
							temp.secondI = i + 2;
							temp.secondJ = j - 1;
							temp.tile = tile;
							if (tile == tempGrid[i + 3][j])
							{
								if (tile == tempGrid[i + 4][j])
								{
									temp.size = 5;
								}
								else
								{
									temp.size = 4;
								}
							}
							else
							{
								temp.size = 3;
							}
						}
						else if (tile == tempGrid[i + 2][j + 1])
						{
							temp.firstI = i;
							temp.firstJ = j;
							temp.secondI = i + 2;
							temp.secondJ = j - 1;
							temp.tile = tile;
							if (tile == tempGrid[i + 3][j])
							{
								if (tile == tempGrid[i + 4][j])
								{
									temp.size = 5;
								}
								else
								{
									temp.size = 4;
								}
							}
							else
							{
								temp.size = 3;
							}
						}
					}
				}
			}
			if (temp.size != 0)
			{
				moves.push_back(temp);
			}
		}
	}

	return moves;

}

vector<Move> Grid::getVerticalMoves(std::vector<Move> moves) {
	Move temp;
	int tile, tempGrid[10][10] = { 0 };
	//reading grid into slightly larger grid with a buffer of -1's around it to allow for easy comparison
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			tempGrid[i][j] == grid[i - 1][j - 1];
		}
	}
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			temp.firstI = 0;
			temp.firstJ = 0;
			temp.secondI = 0;
			temp.secondJ = 0;
			temp.tile = 0;
			temp.size = 0;
			tile = tempGrid[i][j];
			//for every co-ordinate in the grid
			if (tile == tempGrid[i][j + 1] || tempGrid[i][j] == tempGrid[i][j + 2])
			{
				if (tile == tempGrid[i ][j+ 2])
				{
					if (tile == tempGrid[i - 1][j + 1])
					{
						temp.firstI = i;
						temp.firstJ = j;
						temp.secondI = i - 1;
						temp.secondJ = j + 1;
						temp.tile = tile;

						if (tile == tempGrid[i][j + 3])
						{
							temp.size = 4;

						}
						else if (tile == tempGrid[i][j - 1])
						{
							temp.size = 4;
						}
						else
						{
							temp.size = 3;
						}
					}
					else if (tile == tempGrid[i + 1][j + 1])
					{
						temp.firstI = i;
						temp.firstJ = j;
						temp.secondI = i + 1;
						temp.secondJ = j + 1;
						temp.tile = tile;

						if (tile == tempGrid[i][ j+ 3])
						{
							temp.size = 4;
						}
						else if (tile == tempGrid[i][ j- 1])
						{
							temp.size = 4;
						}
						else
						{
							temp.size = 3;
						}
					}///
					else
					{
						if (tile == tempGrid[i - 1][j + 2])//x10/x20/x03
						{
							temp.firstI = i;
							temp.firstJ = j;
							temp.secondI = i - 1;
							temp.secondJ = j + 2;
							temp.tile = tile;
							if (tile == tempGrid[i][j + 3])
							{
								if (tile == tempGrid[i][j + 4])
								{
									temp.size = 5;
								}
								else
								{
									temp.size = 4;
								}
							}
							else
							{
								temp.size = 3;
							}
						}
						else if (tile == tempGrid[i + 1][j + 2])
						{
							temp.firstI = i;
							temp.firstJ = j;
							temp.secondI = i - 1;
							temp.secondJ = j + 2;
							temp.tile = tile;
							if (tile == tempGrid[i][j + 3])
							{
								if (tile == tempGrid[i][j + 4])
								{
									temp.size = 5;
								}
								else
								{
									temp.size = 4;
								}
							}
							else
							{
								temp.size = 3;
							}
						}
					}
				}
			}
			if (temp.size != 0)
			{
				moves.push_back(temp);
			}
		}
	}

	return moves;

}