#include <iostream>
#include "gridInit.h"

class GridHandle : public GridInit
{
public:
	//init grid handle
	GridHandle();

	//test -- print grid
	void printGrid();

	//swap two positions
	void swapPositions(int pos1i, int pos1j, int pos2i, int pos2j );

	//drop down tiles -- performs 'bubble sort'
	void dropDown();
	//algorithm used in dropDown()
	void dropSortAlgorithm(int index);

	//weighting handling
	void weighting();

	//check area around where swap is made and remove match
	void checkSwapArea(int pos1i, int pos1j, int pos2i, int pos2j);

	//sets removed blocks to 0 then calls dropDown
	void removeFromGrid();

};