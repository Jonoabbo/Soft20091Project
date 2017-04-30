#pragma once

#include "PlayerClass.h"

class EnemyClass: public PlayerClass
{	
public:
	int difficulty;
	
	int weighting(int tile, int size);
	void adjustDifficulty(int);

	EnemyClass(int newHP, int newDiff);
	
};