#include "PlayerClass.h"


PlayerClass::PlayerClass()
{
		hp = 50;
		red, blue, green, yellow = 0;
}

void PlayerClass::adjustHp(int newHP)
{
	hp = newHP;
}

void PlayerClass::adjustRed(int newRed)
{
	red = newRed;
}
void PlayerClass::adjustBlue(int newBlue) {
	blue = newBlue;
}
void PlayerClass::adjustYellow(int newYellow) 
{
	yellow = newYellow;
}

void PlayerClass::adjustGreen(int newGreen) 
{
	green = newGreen;
}
