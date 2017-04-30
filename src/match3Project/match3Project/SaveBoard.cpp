#include "stdafx.h"
#include "playerClass.h"
#include "SaveBoard.h"
#include <string>
#include <vector>

using namespace std;
saveBoard::saveBoard(playerClass player, enemyClass enemy, string board)
{
	vector<string> saveData;

	//Save profile data
	saveData.push_back(player.getProfileName());
}