#include "grid.h"

class GridInit : public Grid
{
public:
	//initialises grid
	GridInit();

	int checkForMatches();

	void createGrid();
};