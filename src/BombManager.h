#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "ResourceManager.h"
#include "Bomb.h"

class BombManager
{
private:
	BombManager(){}

	BombManager(const BombManager&);
	BombManager& operator=(const BombManager&);

public:

	std::vector<Bomb>	m_bombVector;

	static BombManager* Instance();

	void Add(int tileXindex, int tileYindex, BombTypes types);
	void Render();
	void Update();
	void Delete(int id);

	Bomb* CheckCollision(float xPos, float yPos);
};