#pragma once

#include "PlayerClass.h"

class enemyClass: public playerClass
{	
public:
	int difficulty;
	int weighting(int tile, int size);
	void adjustDifficulty(int);

	enemyClass();
	enemyClass(int newHP, int newDiff);
	
};