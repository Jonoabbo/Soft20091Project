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
	saveData.push_back(player.getProfileName);
	saveData.push_back("<character>");
	saveData.push_back(player.getCharacterName);
	saveData.push_back("<playerData>");
	saveData.push_back(stoi(player.getHp));
	saveData.push_back(stoi(player.getRed));
	saveData.push_back(stoi(player.getBlue));
	saveData.push_back(stoi(player.getYellow));
	saveData.push_back(player.getGreen());
	saveData.push_back("</playerData>");
	saveData.push_back("<enemyData>");
	saveData.push_back(stoi(enemy.getHp));
	saveData.push_back(stoi(enemy.getRed));
	saveData.push_back(stoi(enemy.getBlue));
	saveData.push_back(stoi(enemy.getYellow));
	saveData.push_back(stoi(enemy.getGreen));
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
	vector<string> temp;
	fstream myFile;
	myFile.open("gameSaves.xml", ios::in);
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			if (line = "<root>")
			{
				for (int n = 0; n < saveData.size(); n++)
				{
					temp.push_back(saveData[n]);
				}
			}
			temp.push_back(line);
		}
	}
	myFile.close;

	myFile.open("gamesSaves.xml", ios::out);
	if (myFile.is_open())
	{
		for (int n = 0; n < temp.size(); n++)
		{
			myFile << temp[n];
		}
	}
}