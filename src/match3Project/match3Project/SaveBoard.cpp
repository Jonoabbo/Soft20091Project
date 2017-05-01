#include "stdafx.h"
#include "SaveBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
saveBoard::saveBoard() {

}

saveBoard::saveBoard(struct saveFile saveF)
{
	
	vector<string> saveData;
	//Save profile data
	saveData.push_back("<profile>");
	saveData.push_back(saveF.player.getProfileName());
	saveData.push_back("<character>");
	saveData.push_back(saveF.player.getCharacterName());
	saveData.push_back("<playerData>");
	saveData.push_back(to_string(saveF.player.getHp()));
	saveData.push_back(to_string(saveF.player.getRed()));
	saveData.push_back(to_string(saveF.player.getBlue()));
	saveData.push_back(to_string(saveF.player.getYellow()));
	saveData.push_back(to_string(saveF.player.getGreen()));
	saveData.push_back("</playerData>");
	saveData.push_back("<enemyData>");
	saveData.push_back(to_string(saveF.enemy.getDifficulty()));
	saveData.push_back(to_string(saveF.enemy.getHp()));	
	saveData.push_back(to_string(saveF.enemy.getRed()));
	saveData.push_back(to_string(saveF.enemy.getBlue()));
	saveData.push_back(to_string(saveF.enemy.getYellow()));
	saveData.push_back(to_string(saveF.enemy.getGreen()));
	saveData.push_back("</enemyData>");
	saveData.push_back("<board>");
	saveData.push_back(saveF.board);
	saveData.push_back("</board>");	
	saveData.push_back("</character>");
	saveData.push_back("</profile>");
	save(saveData);

}

void saveBoard::save(vector<string> saveData) {
	string line;
	vector<string> temp;
	fstream saveFile;
	saveFile.open("gameSaves.xml", ios::in);
	if (saveFile.is_open())
	{
		while (getline(saveFile, line))
		{
			temp.push_back(line);
			if (line =="<root>")
			{
				for (int n = 0; n < saveData.size(); n++)
				{
					temp.push_back(saveData[n]);
				}
			}
			
		}
	}
	saveFile.close();

	saveFile.open("gamesSaves.xml", ios::out);
	if (saveFile.is_open())
	{
		for (int n = 0; n < temp.size(); n++)
		{
			saveFile << temp[n];
		}
	}
}