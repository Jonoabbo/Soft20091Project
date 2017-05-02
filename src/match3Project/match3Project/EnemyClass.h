#pragma once

#include "PlayerClass.h"
#include <vector>
#include <time.h>

class enemyClass: public playerClass
{	
private:
	int difficulty, redWeight,blueWeight,YellowWeight,greenWeight;
	
	
public:
	
	int weighting(int tile, int size);
	void adjustDifficulty(int);
	int getDifficulty();
	enemyClass();
	enemyClass(int newHP);
	void enemyFavourite();
	std::vector<int> getWeighting(std::vector<int>);
	
};