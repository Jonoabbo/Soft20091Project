#pragma once
#include "EnemyClass.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include <string>
#include <vector>
using namespace std;

class loadBoard {
public:
	loadBoard();

	//Load all the character names associated with a profile
	vector<string> characterNames(string profileName);

	//Return save file associated with a character name
	saveFile loadCharacter(string profileName, string charName);

	//Return the save with the longest run
	saveFile getHardest(string profileName);
};