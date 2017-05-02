#pragma once
#include <string>
#include <vector>
class fileHandler {
public:
	std::vector<std::string> checkProfile(std::string profileName);
	std::vector<std::string> checkCharacters(std::string profileName, std::string characterName);
	void addProfile(std::string profileName);
	void addCharacter(std::string profileName, std::string characterName);
};