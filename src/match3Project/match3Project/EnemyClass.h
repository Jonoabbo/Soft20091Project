#pragma once

#include "PlayerClass.h"

class EnemyClass: public PlayerClass
{	
public:
	int difficulty;

	int weighting(int, int);
	void adjustDifficulty(int);
	
};