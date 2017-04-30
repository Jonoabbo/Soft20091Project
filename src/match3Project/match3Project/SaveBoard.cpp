#include "stdafx.h"
#include "SaveBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
saveBoard::saveBoard(playerClass player, enemyClass enemy, string board)
{
	vector<string> saveData;

	//Save profile data
	saveData.push_back("<profile>");
	saveData.push_back(player.getProfileName());
	saveData.push_back("<character>");
	saveData.push_back(player.getCharacterName);
	saveData.push_back("<playerData>");
	saveData.push_back(player.getHp());
	saveData.push_back(player.getRed());
	saveData.push_back(player.getBlue());
	saveData.push_back(player.getYellow());
	saveData.push_back(player.getGreen());
	saveData.push_back("</playerData>");
	saveData.push_back("<enemyData>");
	saveData.push_back(enemy.getHp());
	saveData.push_back(enemy.getRed());
	saveData.push_back(enemy.getBlue());
	saveData.push_back(enemy.getYellow());
	saveData.push_back(enemy.getGreen());
	saveData.push_back("</enemyData>");
	saveData.push_back("<board>");
	saveData.push_back(board);
	saveData.push_back("</board>");	
	saveData.push_back("</character>");
	saveData.push_back("</profile>");
	save(saveData);

}

void saveBoard::save(vector<string> saveData) {
	string line;
	ifstream myFile;
	myFile.open("gameSaves.xml");
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			if (line = "<root>")
			{

			}
		}
	}
}