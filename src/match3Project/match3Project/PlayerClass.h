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
	playerClass(std::string profileName, std::string characterName);
	playerClass();
	
	void adjustHp(int);
	void adjustRed(int);
	void adjustBlue(int);
	void adjustYellow (int);
	void adjustGreen(int);
	int getHp();
	int getRed();
	int getBlue();
	int getYellow();
	int getGreen();
	std::string getProfileName();
	std::string getCharacterName();
	
	
};