#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "LevelManager.h"

class CollisionManager
{
private:
	CollisionManager(){}

	CollisionManager(const CollisionManager&);
	CollisionManager& operator=(const CollisionManager&);

public:

	static CollisionManager* Instance();

	Tile*	CheckCollision(int xPos, int yPos, POINT direction);
	Tile*	GetTile(float xPos, float yPos);
};