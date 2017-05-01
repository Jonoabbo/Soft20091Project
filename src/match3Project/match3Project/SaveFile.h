#pragma once

#include "EnemyClass.h"
#include "PlayerClass.h"

struct saveFile {
	std::string board;
	playerClass player;
	enemyClass enemy;
};