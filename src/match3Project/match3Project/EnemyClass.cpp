#include "stdafx.h"
#include "EnemyClass.h"


int enemyClass::weighting(int tile, int size)
	{
		switch (tile)
		{
		case 1:
			if (size == 4) 
			{
				return redWeight*size;
			}
			else if (size == 5)
			{
				return redWeight * 2 * size;
			}
			return redWeight*(size - 1);
		case 2:
			if (size == 4)
			{
				return blueWeight*size;
			}
			else if (size == 5)
			{
				return blueWeight * 2 * size;
			}
			return blueWeight*(size - 1);
		case 3:
			if (size == 4)
			{
				return YellowWeight*size;
			}
			else if (size == 5)
			{
				return YellowWeight * 2 * size;
			}
			return YellowWeight*(size - 1);
		case 4:
			if (size == 4)
			{
				return greenWeight*size;
			}
			else if (size == 5)
			{
				return greenWeight * 2 * size;
			}
			return greenWeight*(size - 1);
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
void enemyClass::adjustDifficulty(int newDiff)
{
	difficulty -= newDiff;

}
int enemyClass::getDifficulty()
{
	return difficulty;
}

enemyClass::enemyClass(){
	hp = 50;
	difficulty = 5;
	red = 0, blue = 0, green = 0, yellow = 0;
	redWeight = 1, blueWeight = 1, YellowWeight = 1, greenWeight = 1;
	enemyFavourite();
}		
enemyClass::enemyClass(int newHp = 0) {
	hp = newHp;
	red = 0, blue = 0, green = 0, yellow = 0;
	redWeight = 1, blueWeight = 1, YellowWeight = 1, greenWeight = 1;
	enemyFavourite();
}
void enemyClass::enemyFavourite() {
	int temp = rand() % 4;
	switch (temp) 
	{	
		case 0:
			redWeight = 2;
			break;
		case 1:
			blueWeight = 2;
			break;
		case 2: 
			YellowWeight = 2;
			break;
		case 3:
			greenWeight = 2;
			break;
	}
}
std::vector<Move> enemyClass::getWeighting(std::vector<Move> moves) {
	for (int i = 0; i < moves.size(); 0)
	{
		moves[i].weighting = weighting(moves[i].tile, moves[i].size);
	}
	return moves;
}
