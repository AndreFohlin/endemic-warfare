#pragma once
#include <iostream>
#include "Tinyxml.h"
#include <vector>

class Highscore
{
public:
	Highscore(void);
	~Highscore(void);

	// -Create a highscore file
	void CreateHighscore(std::string fileName, int listSize);

	// -Add To highscore file
	void AddToHighscore(std::string name, int score);

	// -Read highscore file
	void ReadHighscore(std::string fileName);

private:

	// -Nr of elements
	int listElements;

	// -Name
	std::string listName[10];
	// -Score
	std::vector<int> listScore;

	// -XML document
	TiXmlDocument highscoreDoc;

	// -path to XML file
	std::string xmlPath;
};
