#include "stdafx.h"
#include "SaveBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
saveBoard::saveBoard() {

}

saveBoard::saveBoard(saveFile saveF)
{
	
	vector<string> saveData;
	//Save profile data
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
	save(saveData,saveF.player.getProfileName, saveF.player.getCharacterName);

}

void saveBoard::save(vector<string> saveData, string profileName, string characterName)
{
	string line;
	vector<string> temp;

	//character name
	string playerChar = saveData[3];
	//profile name
	string playerProfile = saveData[1];
	
	fstream saveFile;
	saveFile.open("gamesSaves.xml", ios::in);
	if (saveFile.is_open)
	{
		while (getline(saveFile, line))
		{
			temp.push_back(line);
			if (line == "<profile>")
			{
				getline(saveFile, line);
				temp.push_back(line);
				if (line == profileName)
				{
					while (line != "</profile>") 
					{
						getline(saveFile, line);
						temp.push_back(line);
						if (line == "<character>")
						{
							getline(saveFile, line);
							temp.push_back(line);
							if(line == characterName)
							{
								for (int n = 0; n < saveData.size(); n++)
								{
									temp.push_back(saveData[n]);
								}
							}
						}
					}
				}

			}
		}
	}	else
	{
		//if the file is empty do this
		temp.push_back("<root>");
		for (int n = 0; n < saveData.size(); n++)
		{
			temp.push_back(saveData[n]);
		}
		temp.push_back("</root>");
	}

	saveFile.open("gamesSaves.xml", ios::out);
	if (saveFile.is_open())
	{
		for (int n = 0; n < temp.size(); n++)
		{
			saveFile << temp[n] + "\n";
		}
	}

	saveFile.close();

}