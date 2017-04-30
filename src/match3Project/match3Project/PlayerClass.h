#pragma once


class playerClass
{
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