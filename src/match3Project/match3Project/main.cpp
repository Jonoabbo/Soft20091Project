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
	GridInit test;

	std::string hello = test.writeToString();

	std::cout << hello << std::endl;

	GridHandle HandleTest;
	playerClass player;
	enemyClass enemy;

	//testing
	player.adjustRed(12);
	player.adjustBlue(12);
	player.adjustYellow(12);
	player.adjustGreen(12);

	

	HandleTest.readFromString(hello);

	saveBoard newSave(HandleTest.saveGame(hello));

	loadBoard loadSave;
	
	saveFile testSaveFile;

	testSaveFile = loadSave.loadCharacter("Default Profile", "Default Character");

	std::string newString = testSaveFile.board;
	std::cout << "Board is: ";
	std::cout << newString << std::endl;

	int a, b, c, d;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	HandleTest.swapPositions(a, b, c, d);



	return 0;
}


