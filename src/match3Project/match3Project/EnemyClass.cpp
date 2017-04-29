#include "stdafx.h"
#include "EnemyClass.h"


int EnemyClass::weighting(int tile, int size)
	{
		switch (tile)
		{
		case 1:
			if (size == 4) 
			{
				return red*size;
			}
			else if (size == 5)
			{
				return red * 2 * size;
			}
			return red*(size - 1);
		case 2:
			if (size == 4)
			{
				return blue*size;
			}
			else if (size == 5)
			{
				return blue * 2 * size;
			}
			return blue*(size - 1);
		case 3:
			if (size == 4)
			{
				return yellow*size;
			}
			else if (size == 5)
			{
				return yellow * 2 * size;
			}
			return yellow*(size - 1);
		case 4:
			if (size == 4)
			{
				return green*size;
			}
			else if (size == 5)
			{
				return green * 2 * size;
			}
			return green*(size - 1);
		case 5:
			if (size == 4)
			{
				return 9;
			}
			else if (size == 5)
			{
				return 10;
			}
			return 3;
		}
	}
void EnemyClass::adjustDifficulty(int newDiff)
{
	difficulty = newDiff;

}

EnemyClass::EnemyClass(){
	hp = 50;
	difficulty = 5;
}		
