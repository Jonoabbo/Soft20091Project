#include "stdafx.h"
#include "LoadBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

loadBoard::loadBoard()
{	
}
saveFile loadBoard::loadCharacter(string profileName, string charName) {
	saveFile loadedFile;		
	string line;
	fstream saveFile;
	saveFile.open("gameSaves.xml", ios::in);

	if (saveFile.is_open())
	{
		while(getline(saveFile,line))
		{
			if (line == "<profile>")
			{
				getline(saveFile, line);
				if (line == profileName)
				{
					loadedFile.player.setProfileName(profileName);
					//go through every line in the profile
					while (line != "</profile>")
					{
						getline(saveFile, line);

						//If the line is <character>
						if (line == "<character>")
						{
							getline(saveFile, line);
							if (line == charName)
							{
								loadedFile.player.setCharacterName(charName);
								while (line != "</character>")
								{
									getline(saveFile, line);
									if(line =="<playerData>")
									{ 
										getline(saveFile, line);
										loadedFile.player.adjustHp(stoi(line));	
										getline(saveFile, line);
										loadedFile.player.adjustRed(stoi(line));					
										getline(saveFile, line);
										loadedFile.player.adjustBlue(stoi(line));
										getline(saveFile, line);
										loadedFile.player.adjustYellow(stoi(line));
										getline(saveFile, line);
										loadedFile.player.adjustGreen(stoi(line));
									}
									else if (line == "<enemyData>")
									{
										getline(saveFile, line);
										loadedFile.enemy.adjustDifficulty(stoi(line));								
										getline(saveFile, line);
										loadedFile.enemy.adjustHp(stoi(line));								
										getline(saveFile, line);
										loadedFile.enemy.adjustRed(stoi(line));
										getline(saveFile, line);
										loadedFile.enemy.adjustBlue(stoi(line));
										getline(saveFile, line);
										loadedFile.enemy.adjustYellow(stoi(line));
										getline(saveFile, line);
										loadedFile.enemy.adjustGreen(stoi(line));
									}
									else if(line == "<board>")
									{
										getline(saveFile, line);
										loadedFile.board = line;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	saveFile.close();

	return loadedFile;
}

saveFile loadBoard::getHardest(string profileName) {
	saveFile loadedFile;	
	string line;
	bool profileFound = false;
	int hardest = 6,  position, counter= 0;
	fstream saveFile;
	saveFile.open("gameSaves.xml", ios::in);

	if (saveFile.is_open())
	{
		//Look through each line until the profile is found
		while (getline(saveFile, line))
		{
			if (line == "<profile>")
			{
				getline(saveFile, line);
				while (line != "</profile>")
				{

					getline(saveFile, line);
					if (line == "<enemyData>")
					{
						counter++;
						getline(saveFile, line);
						//The lower the number the harder game
						if (stoi(line) < hardest)
						{
							position = counter;
							hardest = stoi(line);
						}
					}
				}
			}
		}
	}
	saveFile.close();

			counter = 0;
			saveFile.open("gameSaves.xml", ios::in);
			if (saveFile.is_open())
			{
				//Look through each line until the profile is found
				while (getline(saveFile, line))
				{
					if (line == "<profile>")
					{
						getline(saveFile, line);
						loadedFile.player.setProfileName(line);
						while (line != "</profile>")
						{
							getline(saveFile, line);
							if (line == "<character>")
							{
								getline(saveFile, line);
								loadedFile.player.setCharacterName(line);
								counter++;
								if (counter == position)
								{
									while (line != "</character>")
									{
										getline(saveFile, line);
										if (line == "<playerData>")
										{
											getline(saveFile, line);
											loadedFile.player.adjustHp(stoi(line));
											getline(saveFile, line);
											loadedFile.player.adjustRed(stoi(line));
											getline(saveFile, line);
											loadedFile.player.adjustBlue(stoi(line));
											getline(saveFile, line);
											loadedFile.player.adjustYellow(stoi(line));
											getline(saveFile, line);
											loadedFile.player.adjustGreen(stoi(line));
										}
										else if (line == "<enemyData>")
										{
											getline(saveFile, line);
											loadedFile.enemy.adjustDifficulty(stoi(line));
											getline(saveFile, line);
											loadedFile.enemy.adjustHp(stoi(line));
											getline(saveFile, line);
											loadedFile.enemy.adjustRed(stoi(line));
											getline(saveFile, line);
											loadedFile.enemy.adjustBlue(stoi(line));
											getline(saveFile, line);
											loadedFile.enemy.adjustYellow(stoi(line));
											getline(saveFile, line);
											loadedFile.enemy.adjustGreen(stoi(line));
										}
										else if (line == "<board>")
										{
											getline(saveFile, line);
											loadedFile.board = line;
										}
										
									}
								}
							}
						}
					
				
			}
		}

		saveFile.close();
	}

	return loadedFile;
}


