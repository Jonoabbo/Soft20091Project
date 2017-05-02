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
	void saveVector(vector<string> saveData, string profileName, string characterName);
public:
	void save(saveFile);
	saveBoard();
	
	//
};