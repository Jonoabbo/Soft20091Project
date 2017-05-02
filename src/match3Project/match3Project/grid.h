#pragma once
#include "Move.h";
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

class Grid{
public:

	Grid();

	std::vector<int> findMatchHorizontal(int row);

	std::vector<int> findMatchVertical(int column);

	std::vector<Move> getMoves();
	
	
	//writeGridToString + return
	std::string writeToString();

protected:
	int grid[8][8];
	std::vector<Move> getHorizontalMoves(std::vector<Move>);
	std::vector<Move> getVerticalMoves(std::vector<Move>);
	

};