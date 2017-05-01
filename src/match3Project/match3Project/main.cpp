// match3Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "grid.h"
#include "gridInit.h"
#include "gridHandle.h"
#include "SaveFile.h"
#include "SaveBoard.h"
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

	int a, b, c, d;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;

	HandleTest.swapPositions(a, b, c, d, player, enemy);



	return 0;
}


