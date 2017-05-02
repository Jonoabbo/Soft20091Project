#include <iostream>
#include "grid.h"
#include "PlayerClass.h"
#include "SaveFile.h"
#include "EnemyClass.h"
#include "Move.h"
#include <vector>

class GridHandle : public Grid
{
public:

	playerClass player;
	enemyClass enemy;	
	bool playersTurn = true;
	//default constructor grid handle
	GridHandle();

	GridHandle(playerClass p, enemyClass e, std::string board);
	//print grid
	void printGrid();

	//createGridFromString
	void readFromString(std::string r);

	//swap two positions
	void swapPositions(Move moves);

	//save the game
	saveFile saveGame(std::string test);

	//get player hp
	int getPlayerHp();

	//get enemy hp
	int getEnemyHp();

	//get player
	playerClass getPlayer();

	//get enemy
	enemyClass getEnemy();

private:
	//drop down tiles -- performs 'bubble sort'
	void dropDown();
	//algorithm used in dropDown()
	void dropSortAlgorithm(int index);

	//check area around where swap is made and remove match
	bool checkSwapArea(Move moves);

	//sets removed blocks to 0 then calls dropDown
	void removeFromGrid();

	//Choose the move from existing moves
	void enemyMove(std::vector<Move>);

	//sets given position to zero
	void setPosZero(int i, int j);
};