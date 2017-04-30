#include "stdafx.h"
#include "PlayerClass.h"

using namespace std;

playerClass::playerClass()
{
	hp = 50;
	profile = "Default Profile";
	character = "Default Character";
	red, blue, green, yellow = 0;
}

playerClass::playerClass(string profileName,string characterName)
{
		hp = 50;
		profile = profileName;
		character = characterName;
		red, blue, green, yellow = 0;
}

string playerClass::getProfileName() {
	string name;
	 name= profile;
	return name;
}

string playerClass::getCharacterName() {
	string name;
	name = character;
	return name;
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
