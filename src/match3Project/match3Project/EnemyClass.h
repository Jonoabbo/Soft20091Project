#pragma once

#include "PlayerClass.h"

class enemyClass: public playerClass
{	
private:
	int difficulty;
	
public:
	
	int weighting(int tile, int size);
	void adjustDifficulty(int);
	int getDifficulty();
	enemyClass();
	enemyClass(int newHP, int newDiff);
	
};