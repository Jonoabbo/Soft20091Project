#pragma once
#include <string>

class playerClass
{
private:
	std::string profile;
	std::string character;
protected:
	int hp, red, blue, green, yellow;
public:
	playerClass(string profileName, string characterName);
	playerClass();
	std::string getProfileName();
	std::string getCharacterName();
	void adjustHp(int);
	void adjustRed(int);
	void adjustBlue(int);
	void adjustYellow (int);
	void adjustGreen(int);
	
	
};