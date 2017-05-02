#pragma once
#include "fileHandler.h"
#include "EnemyClass.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include <string>
#include <vector>
using namespace std;

class loadBoard : public fileHandler {
public:
	loadBoard();
	
	//Return save file associated with a character name
	saveFile loadCharacter(string profileName, string charName);

	//Return the save with the longest run
	saveFile getHardest(string profileName);
};