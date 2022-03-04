#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "ResourceManager.h"
#include "Explosion.h"

class ExplosionManager
{
private:
	ExplosionManager(){}

	ExplosionManager(const ExplosionManager&);
	ExplosionManager& operator=(const ExplosionManager&);

public:

	std::vector<Explosion>	m_explosionVector;

	static ExplosionManager* Instance();

	void Add(int tileXindex, int tileYindex, bool self, POINT dir);
	void Render();
	void Update();
	void Delete(int id);
};