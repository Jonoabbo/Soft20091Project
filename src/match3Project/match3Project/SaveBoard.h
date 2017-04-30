#pragma once
#include "EnemyClass.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include <string>

using namespace std;

class saveBoard {
	playerClass player;
	enemyClass enemy;
	string board;

	saveBoard(playerClass, enemyClass, string board);

};