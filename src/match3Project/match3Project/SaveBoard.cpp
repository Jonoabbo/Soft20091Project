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

void saveBoard::save(vector<string> saveData)
{
	string line;
	vector<string> temp;

	//player name
	string playerName = saveData[3];
	//player profile
	string playerProfile = saveData[1];

	fstream saveFile;
	saveFile.open("gamesSaves.xml", ios::in);
	if (saveFile.is_open())
	{
		//if the file contains data already do this
		getline(saveFile, line);
		temp.push_back(line);
		if (line == "<root>")
		{
			//Look through each line until the profile is found
			while (getline(saveFile, line))
			{
				if (line == "<profile>")
				{
					getline(saveFile, line);
					if (line == playerProfile)
					{
						//profile already exists
						cout << "Profile already exists" << endl;
						break;

						getline(saveFile, line);
						if (line == "<character>")
						{
							while (getline(saveFile, line))
							{
								if (line == playerName)
								{
									cout << "Player name already exists." << endl;
									cout << "Updating current save." << endl;
								}
							}
						}

						break;
					}
				}
			}

			for (int n = 0; n < saveData.size(); n++)
			{
				temp.push_back(saveData[n]);
			}
			 
			while (saveFile.is_open())
			{
				getline(saveFile, line);
				temp.push_back(line);

				if (line == "</root>")
				{
					break;
				}
			}
		}
		saveFile.close();

	}
	else
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