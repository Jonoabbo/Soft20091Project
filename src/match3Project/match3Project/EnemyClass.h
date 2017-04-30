#pragma once

#include "PlayerClass.h"

class enemyClass: public playerClass
{	
private:
	int difficulty;
	
	int weighting(int tile, int size);
public:
	
	void adjustDifficulty(int);

	enemyClass();
	enemyClass(int newHP, int newDiff);
	
};