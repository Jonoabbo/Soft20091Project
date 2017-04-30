#include "stdafx.h"
#include "PlayerClass.h"


playerClass::playerClass()
{
		hp = 50;
		red, blue, green, yellow = 0;
}

void playerClass::adjustHp(int newHP)
{
	hp = newHP;
}

void playerClass::adjustRed(int newRed)
{
	red = newRed;
}
void playerClass::adjustBlue(int newBlue) {
	blue = newBlue;
}
void playerClass::adjustYellow(int newYellow) 
{
	yellow = newYellow;
}

void playerClass::adjustGreen(int newGreen) 
{
	green = newGreen;
}
