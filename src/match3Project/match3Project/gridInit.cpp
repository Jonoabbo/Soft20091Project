#include "stdafx.h"
#include "gridInit.h"

gridInit::gridInit()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int compare = a[i][j];

			if (compare == a[i+1][j])
			{
				if (compare == a[i+2][j])
				{
					std::cout << "Match 3 found at positions: " << i << "," << j << i + 1 << "," << j << i + 2 << "," << j << std::endl;
					//swapPositions(rand of three, rand of three below)

					if (compare == a[i+3][j] && (i <= 4))
					{
						std::cout << "Match 4 found at positions" << i << "," << j << i + 1 << "," << j << i + 2 << "," << j << i + 3 << "," << j << std::endl;

						if (compare == a[i+4][j] && (i <= 3))
						{
							std::cout << "Match 5 found at positions" << i << "," << j << i + 1 << "," << j << i + 2 << "," << j << i + 3 << "," << j << i + 4 << "," << j << std::endl;
						}
					}
				}
			}

		}
	}
}

// example[row][coloum]