// match3Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "grid.h"
#include "gridInit.h"
#include "gridHandle.h"
#include "SaveFile.h"
#include "SaveBoard.h"
#include "LoadBoard.h"
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//##########################################################
	// G A M E  S E T U P
	//##########################################################

	std::cout << "Welcome to Bargin Puzzle Quest" << std::endl;

	vector<std::string> profileChoices;
	vector<std::string> characterChoices;
	loadBoard files;
	saveFile currentSave;
	GridInit genGame;
	

	int profileChoice;
	int charChoice;
	string profileChoiceString;
	string charChoiceString;
	string boardString;

	profileChoices = files.checkProfile();

	std::cout << "There are " << profileChoices.size()+1 << " profiles to choose from:" << std::endl;

	std::cout << "0. New Profile" << std::endl;

	for (int i = 0; i < profileChoices.size(); i++)
	{
		std::cout << i+1 << ". " << profileChoices[i] << std::endl;
	}

	playerClass newPlayer;
	enemyClass newEnemy;

	cout << "Choice: ";
	cin >> profileChoice;

	if (profileChoice == 0)
	{
		cout << "What would you like to call the new Profile?";
		cin >> profileChoiceString;
		files.addProfile(profileChoiceString);
		newPlayer.setProfileName(profileChoiceString);

		cout << "What would you like to call your first character?";
		cin >> charChoiceString;
		files.addCharacter(profileChoiceString, charChoiceString);
		newPlayer.setCharacterName(charChoiceString);

		boardString = genGame.writeToString();
		
		//create new profile
		system("CLS"); //clear screen 
	}
	else
	{
		//load chosen profile
		system("CLS"); //clear screen 

		profileChoiceString = profileChoices[profileChoice - 1];
		characterChoices = files.checkCharacters(profileChoiceString);

		std::cout << "There are " << characterChoices.size() + 2 << " options to choose from:" << std::endl;

		std::cout << "0. *New Profile" << std::endl;
		std::cout << "1. *Load the hardest character" << std::endl;
		for (int i = 0; i < characterChoices.size(); i++)
		{
			std::cout << i + 2 << ". " << characterChoices[i] << std::endl;
		}
		std::cout << "Choice: ";
		std::cin >> charChoice;

		if (charChoice == 0)
		{
			//new character
			cout << "What would you like to call the new character?";
			cin >> charChoiceString;
			files.addCharacter(profileChoiceString, charChoiceString);
			newPlayer.setCharacterName(charChoiceString);

			boardString = genGame.writeToString();
			
		}
		else if (charChoice == 1)
		{
			currentSave = files.getHardest(profileChoiceString);
		}
		else
		{
			charChoiceString = characterChoices[charChoice - 2];
			currentSave = files.loadCharacter(profileChoiceString, charChoiceString);
		}
		
		system("CLS"); //clear screen 

		newPlayer = currentSave.player;
		newEnemy = currentSave.enemy;
		boardString = currentSave.board;

	}

	//##########################################################
	// G A M E  L O O P
	//##########################################################
	GridHandle handler(newPlayer, newEnemy, boardString);
	Move playerMove;
	while (handler.getPlayerHp() > 0 || handler.getEnemyHp > 0)
	{
		cout << "Select the X co-ordinate of the second tile";
		cin >> playerMove.firstI;
		cout << "Select the Y co-ordinate of the second tile";
		cin >> playerMove.firstJ;
		cout << "Select the X co-ordinate of the second tile";
		cin >> playerMove.secondI;
		cout << "Select the Y co-ordinate of the second tile";
		cin >> playerMove.secondJ;
	}
	handler.printGrid();

	//everthing below this is from before and not actually needed

	GridInit test;

	std::string hello = test.writeToString();

	std::cout << hello << std::endl;

	GridHandle HandleTest;
	playerClass player;
	enemyClass enemy;

	player.setCharacterName("HARDFUCKER");
	player.setProfileName("KEV");

	//testing
	player.adjustRed(12);
	player.adjustBlue(12);
	player.adjustYellow(12);
	player.adjustGreen(12);

	enemy.adjustDifficulty(1);

	saveFile newSave;
	saveFile saveLoadTest;

	newSave.player = player;
	newSave.enemy = enemy;
	newSave.board = hello;

	saveBoard Board;

	Board.addProfile(player.getProfileName());
	Board.addCharacter(player.getProfileName(), player.getCharacterName());
	Board.save(newSave);

	HandleTest.readFromString(hello);

	//saveBoard newSave2(HandleTest.saveGame(hello));

	loadBoard loadSave;

	saveLoadTest = loadSave.getHardest(player.getProfileName());

	//saveLoadTest = loadSave.loadCharacter(player.getProfileName(), player.getCharacterName());

	std::cout << saveLoadTest.board << std::endl;
	
	//saveFile testSaveFile;

	//testSaveFile = loadSave.loadCharacter("Default Profile", "Default Character");

	//std::string newString = testSaveFile.board;
	//std::cout << "Board is: ";
	//std::cout << newString << std::endl;

	int a, b, c, d;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	Move playerMove;

	playerMove.firstI = a;
	playerMove.firstJ = b;
	playerMove.secondI = c;
	playerMove.secondJ = d;

	HandleTest.swapPositions(playerMove);


	return 0;
}


