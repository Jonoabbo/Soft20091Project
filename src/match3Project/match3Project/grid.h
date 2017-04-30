#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <string>

class Grid{
public:
	int grid[8][8];

	Grid();

	std::vector<int> findMatchHorizontal(int row);

	std::vector<int> findMatchVertical(int column);

	//writeGridToString + return
	std::string writeToString();

};