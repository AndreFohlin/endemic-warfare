#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <map>

#include "LevelObject.h"
#include "ResourceManager.h"

class LevelManager
{
private:
	LevelManager(){}

	LevelManager(const LevelManager&);
	LevelManager& operator=(const LevelManager&);

	//std::vector <LevelObject> LevelObjects;
	std::map <std::string, LevelObject> LevelObjects;

	LevelObject m_ActiveLevel;

public:

	static LevelManager* Instance();

	void AddLevel(std::string picPath, std::string LevelName);
	void Render();
	void Update();
	
	bool			GetEnemyCollision(float xPos, float yPos);

	LevelObject*	GetActiveLevel() {return &m_ActiveLevel;}
	void			SetActiveLevel(std::string LevelName);
};