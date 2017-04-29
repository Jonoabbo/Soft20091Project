#include "stdafx.h"
#include "GridHandle.h"


GridHandle::GridHandle()
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