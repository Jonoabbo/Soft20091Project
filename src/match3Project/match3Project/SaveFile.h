#pragma once

#include "EnemyClass.h"
#include "PlayerClass.h"

struct saveFile {
	char board[64];
	playerClass player;
	enemyClass enemy;
};