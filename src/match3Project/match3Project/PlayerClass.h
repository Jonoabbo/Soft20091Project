#pragma once
#include <string>

class playerClass
{
private:
	std::string profile;
	std::string character;
	std::string getProfileName();
	playerClass(string profileName, string characterName);
	std::string getCharacterName();
protected:
	int hp, red, blue, green, yellow;
public:
	
	playerClass();
	void adjustHp(int);
	void adjustRed(int);
	void adjustBlue(int);
	void adjustYellow (int);
	void adjustGreen(int);
	
	
};