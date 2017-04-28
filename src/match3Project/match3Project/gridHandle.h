#include <iostream>
#include "gridInit.h"

class GridHandle : public GridInit
{
public:
	//recieve array and store in var
	GridHandle();

	//weighting handling
	void weighting();

	//check area around where swap is made
	void checkSwapArea();
};