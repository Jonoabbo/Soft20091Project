#include <iostream>
#include "gridInit.h"

class GridHandle : public GridInit
{
public:
	//init grid handle
	GridHandle();

	//swap two positions
	void swapPositions();

	//drop down tiles -- performs 'bubble sort'
	void dropDown();

	//weighting handling
	void weighting();

	//check area around where swap is made and remove match
	void checkSwapArea();
};