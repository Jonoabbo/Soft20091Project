#pragma once

#include "PlayerClass.h"
#include "Move.h"
#include <vector>
#include <time.h>

class enemyClass: public playerClass
{	
private:
	int difficulty = 5, redWeight,blueWeight,YellowWeight,greenWeight;
	
	
public:
	
	int weighting(int tile, int size);
	void adjustDifficulty(int);
	int getDifficulty();
	enemyClass();
	enemyClass(int newHP);
	void enemyFavourite();
	std::vector<Move> getWeighting(std::vector<Move>);
	
};