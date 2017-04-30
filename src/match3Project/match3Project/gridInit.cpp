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
	int con = checkForMatches();

	while (con != 0)
	{
		con = checkForMatches();
		std::cout << con << std::endl;
	}
}

int GridInit::checkForMatches()
{
	//search each row
	//counter
	//if next matches increment counter
	//else reset counter
	//if counter ==3 then match 3 found
	//get current element and previous 2
	//randomly change value of one
	//repeat for if counter ==4 or ==5
	//repeat all for columns
	//going across --->

	int nMatchesFound = 0;

	int aCounter = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//going across --->
			if (grid[i][j] == grid[i][j+1])
			{
				aCounter++;
			}

			if (aCounter == 2)
			{
				//reset counter
				aCounter = 0;
				grid[i][j + 1] = rand() % 5 + 1;
				nMatchesFound++;
			}
		}
	}

	int dCounter = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//going d o w n
			if (grid[i][j] == grid[i + 1][j])
			{
				dCounter++;
			}

			if (dCounter == 2)
			{
				//reset counter
				dCounter = 0;
				grid[i + 1][j] = rand() % 5 + 1;
				nMatchesFound++;
			}
		}
	}

	return nMatchesFound;

}

std::vector<int> GridInit::findMatchHorizontal(int row)
{
	int aCounter = 0;
	std::vector<int> matchPositions; //stores 2 ints for each position index form: {i,j} with number to separate the 'matches'

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
				}
			}
			else if (aCounter == 3)
			{
				for (int i = 3; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back((j + 1) - i);
				}
			}
			else if (aCounter == 4)
			{
				for (int i = 4; i > 0; i--)
				{
					matchPositions.push_back(row);
					matchPositions.push_back((j + 1) - i);
				}
			}

			//reset counter
			aCounter = 0;
			grid[row][j + 1] = rand() % 5 + 1;
			//nMatchesFound++;
		}
	}
}

// ##  PLANS FOR CHANGES TO checkForMatches() ##
//	break when comparison isn't true
//	check number on counter
//	then reset to zero
//	return a vector of positions
//	split into two functions one for column one for row

// example[row][coloum]