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


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Welcome to Bargin Puzzle Quest" << std::endl;

	vector<std::string> profileChoices;
	vector<std::string> characterChoices;
	loadBoard files;

	int profileChoice;
	int charChoice;
	string profileChoiceString;

	profileChoices = files.checkProfile();

	std::cout << "There are " << profileChoices.size()+1 << " profiles to choose from:" << std::endl;

	std::cout << "0. New Profile" << std::endl;

	for (int i = 0; i < profileChoices.size(); i++)
	{
		std::cout << i+1 << ". " << profileChoices[i] << std::endl;
	}

	playerClass newPlayer;

	std::cout << "Choice: ";
	std::cin >> profileChoice;

	if (profileChoice == 0)
	{
		//create new profile
	}
	else
	{
		//load chosen profile
		profileChoiceString = profileChoices[profileChoice - 1];

		characterChoices = files.checkCharacters(profileChoiceString);

		std::cout << "There are " << characterChoices.size() << " characters to choose from:" << std::endl;

		std::cout << "0. New Profile" << std::endl;
		for (int i = 0; i < characterChoices.size(); i++)
		{
			std::cout << i + 1 << ". " << characterChoices[i] << std::endl;
		}
		std::cout << "Choice: ";
		std::cin >> charChoice;

		if (charChoice == 0)
		{

		}


		loadBoard loadSave;
		saveFile newSaveFile;
		//newSaveFile = loadSave.getHardest(player.getProfileName());

	}

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


