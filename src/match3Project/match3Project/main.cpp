// match3Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gridInit.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	int grid[8][8];
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

	return 0;
}


