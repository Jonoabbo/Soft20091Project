#include "stdafx.h"
#include "fileHandler.h"
#include <iostream>
#include <fstream>
using namespace std;

vector<string> fileHandler::checkProfile() {
	vector<string> profiles;
	string line;
	fstream saveFile;
	saveFile.open("gameSaves.xml", ios::in);
	if (saveFile.is_open())
	{
		//Look through each line until the profile is found
		while (getline(saveFile, line))
		{
			if (line == "<profile>")
			{
				getline(saveFile, line);
				profiles.push_back(line);
				
			}
		}
	}

	return profiles;
}

vector<string> fileHandler::checkCharacters(string profileName) {
	vector<string> characters;
		string line;
		fstream saveFile;
		saveFile.open("gameSaves.xml", ios::in);
		if (saveFile.is_open())
		{
			//Look through each line until the profile is found
			while (getline(saveFile, line))
			{
				if (line == "<profile>")
				{
					getline(saveFile, line);
					if (line == profileName)
					{
						while (line != "</profile>")
						{
							if (line == "<character>")
							{
								getline(saveFile, line);
								characters.push_back(line);
							}
						}
						
					}
				}
			}
		}
	
	return characters;
}

void fileHandler::addProfile(string profileName) {
	vector<string> exsitingProfiles;
	bool alreadyExsits = false;
	exsitingProfiles = checkProfile();
	vector<string> writeVector;
	
	//Checks if profile already exisits
	if (exsitingProfiles.size() != 0)
	{
		for (int i = 0; i < exsitingProfiles.size(); i++)
		{
			if (exsitingProfiles[i] == profileName)
			{
				alreadyExsits = true;
			}
		}
	}

	if (alreadyExsits == false)
	{
		fstream saveFile;
		string line;

		saveFile.open("gameSaves.xml", ios::in);
		if (saveFile.is_open())
		{			
			while (getline(saveFile, line))
			{
				writeVector.push_back(line);
				if (line == "<root>")
				{
					writeVector.push_back("<profile>");
					writeVector.push_back(profileName);
					writeVector.push_back("</profile>");
				}
			}
			
		}
		else
		{
			saveFile.close();
			saveFile.open("gameSaves.xml", ios::out);
			if (saveFile.is_open())
			{
				//if the file is empty do this
				writeVector.push_back("<root>");
				writeVector.push_back("<profile>");
				writeVector.push_back(profileName);
				writeVector.push_back("</profile>");
				writeVector.push_back("</root>");
			}
		}

		saveFile.close();

		saveFile.open("gameSaves.xml", ios::out);
		if (saveFile.is_open())
		{
			for (int n = 0; n < writeVector.size(); n++)
			{
				saveFile << writeVector[n] + "\n";
			}
		}

		saveFile.close();

	}
}


void fileHandler::addCharacter(string profileName, string characterName) {
	vector<string> exsitingCharacters;
	bool alreadyExsits = false;
	exsitingCharacters = checkCharacters(profileName);
	vector<string> writeVector;

	//Checks if character already exisits
	if (exsitingCharacters.size() != 0)
	{
		for (int i = 0; i < exsitingCharacters.size(); i++)
		{
			if (exsitingCharacters[i] == characterName)
			{
				alreadyExsits = true;
			}
		}
	}

	if (alreadyExsits == false)
	{
		fstream saveFile;
		string line;

		saveFile.open("gameSaves.xml", ios::in);
		if (saveFile.is_open())
		{
			while (getline(saveFile, line))
			{				
				writeVector.push_back(line);
				if (line == "<profile>")
				{
					getline(saveFile, line);
					writeVector.push_back(line);
					if (line == profileName)
					{
						writeVector.push_back("<character>");
						writeVector.push_back(characterName);
						writeVector.push_back("</character>");
						//getline(saveFile,line);
						/*if (exsitingCharacters.size() != 0)
						{
							while (line != "<character>")
							{
								getline(saveFile, line);
							}
						}*/
						
					}
				}
			}			
		}
		saveFile.close();

		saveFile.open("gameSaves.xml", ios::out);
		if (saveFile.is_open())
		{
			for (int n = 0; n < writeVector.size(); n++)
			{
				saveFile << writeVector[n] + "\n";
			}
		}

		saveFile.close();

	}
}