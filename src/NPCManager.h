#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

#include "ResourceManager.h"
#include "AIDigger.h"

class NPCManager
{
private:
	NPCManager(){}

	NPCManager(const NPCManager&);
	NPCManager& operator=(const NPCManager&);

public:

	std::vector<AIDigger>	m_diggerVector;

	static NPCManager* Instance();

	void Add(int tileXindex, int tileYindex, NPCTypes types);
	void Render();
	void Update(Player* player);
	void Delete(int id);
};