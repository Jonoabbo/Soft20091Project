#pragma once
#include "EnemyClass.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include <string>
#include <vector>
using namespace std;

class saveBoard {
	playerClass player;
	enemyClass enemy;
	string board;
	saveBoard();
	saveBoard(struct saveFile);
	void save(vector<string> saveData);

};