#include "grid.h"

class GridInit : public Grid
{
public:
	//initialises grid
	GridInit();

private:
	int preventThrees();

	void createGrid();
};