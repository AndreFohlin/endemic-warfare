#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "TileManager.h"
#include "RenderWindow.h"
#include "TinyXML.h"
#include "Player.h"
#include "Item.h"
#include <vector>
#include "AIDigger.h"
#include "PlayerTeleporter.h"
#include "EnemySpawn.h"

class LevelObject
{
public:
	LevelObject(void);
	~LevelObject(void);

	void Create(std::string xmlPath);
	void Update();
	void Render();

	bool CheckNPC(float xPos, float yPos);

	TileManager* GetTileManager() {return &m_TileManager;}
	Player* GetPlayer(){return &m_Player;}

	EnemySpawn	GetEnemySpawn(int index);

private:

	AIDigger m_Diggers[8];
	Player m_Player;
	TileManager	m_TileManager;
	PlayerTeleporter m_PlayerTeleporter;
	EnemySpawn	m_enemySpawn[4];

	std::vector<Item> m_Items;
	std::vector<AIDigger> m_ai;

	bool CreateMap		(std::string pic, int tileX, int tileY);
	bool CreatePlayer	(std::string pic, int startX, int startY);
	bool CreateItems	(std::string xml);
	bool CreateEnemies	(std::string xml);

	void CreateSpawnPoints();

	
};