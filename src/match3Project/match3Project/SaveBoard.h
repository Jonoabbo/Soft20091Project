#pragma once
#include "fileHandler.h"
#include "EnemyClass.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include <string>
#include <vector>
using namespace std;

class saveBoard : public fileHandler {
	playerClass player;
	enemyClass enemy;
	string board;
public:
	saveBoard::saveBoard(saveFile);
	saveBoard();
	void save(vector<string> saveData, string profileName, string characterName);

};