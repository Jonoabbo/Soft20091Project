#include <iostream>
#include "grid.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include "EnemyClass.h"

class GridHandle : public Grid
{
public:

	playerClass p;
	enemyClass e;
	//default constructor grid handle
	GridHandle();
	//If not loading a save file
	GridHandle(playerClass& p, enemyClass& e);
	//if loading a save file
	GridHandle(playerClass& p, enemyClass& e, string board);
	//test -- print grid
	void printGrid();

	//createGridFromString
	void readFromString(std::string r);

	//swap two positions
	void swapPositions(int pos1i, int pos1j, int pos2i, int pos2j);

	//save the game
	saveFile saveGame(playerClass p, enemyClass e);

private:
	//drop down tiles -- performs 'bubble sort'
	void dropDown();
	//algorithm used in dropDown()
	void dropSortAlgorithm(int index);

	//check area around where swap is made and remove match
	bool checkSwapArea(int pos1i, int pos1j, int pos2i, int pos2j);

	//sets removed blocks to 0 then calls dropDown
	void removeFromGrid();

	//OLIVER TO IMPLEMENT -- you handle this part
	void checkForPossibleSwaps();

	//sets given position to zero
	void setPosZero(int i, int j);

	void incrementResource(int resource);
};