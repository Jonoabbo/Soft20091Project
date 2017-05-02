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
	saveBoard saving;
	int playerInput;

	while (handler.getPlayerHp() > 0 || handler.getEnemyHp() > 0)
	{
		handler.printGrid();
		if (handler.playersTurn == true)
		{
			cout << "What would you like to do?" << endl;
			cout << "1: Make Move" << endl;
			cout << "2: Save game" << endl;
			cout << "3: Check Player" << endl;
			cout << "4: Check Enemy" << endl;
			cin >> playerInput;
			switch (playerInput) 
			{
			case 1:
				cout << "Select the X co-ordinate of the second tile";
				cin >> playerMove.firstI;
				cout << "Select the Y co-ordinate of the second tile";
				cin >> playerMove.firstJ;
				cout << "Select the X co-ordinate of the second tile";
				cin >> playerMove.secondI;
				cout << "Select the Y co-ordinate of the second tile";
				cin >> playerMove.secondJ;
				break;
			case 2:				
				saving.save(handler.saveGame());
				cout << "Saved!" << endl;
				cin >> playerInput;
				break;
			case 3:
				cout << "PlayerHp: " << handler.getPlayerHp() << endl;
				cin >> playerInput;
			case 4:
				cout << "EnemyHp: " << handler.getPlayerHp() << endl;
				cin >> playerInput;

			}
		}
		else
		{
			handler.enemyMove(handler.getMoves());
		}
		
	}
	

	//everthing below this is from before and not actually needed
	return 0;
}


