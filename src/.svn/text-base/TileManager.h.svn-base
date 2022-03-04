#pragma once
#include "Tile.h"
#define MAPHEIGHT 40//80
#define MAPWIDTH 64//128

class TileManager
{
public:
	TileManager(void);
	~TileManager(void);

	void		Render();
	void		Update();
	void		InitTiles(sf::Image* tilemap,unsigned int tileheight, unsigned int tilewidth);
	Tile*		GetTile(unsigned int x, unsigned int y);
	Tile*		GetTileFromPosition(float x, float y);
	void		SpreadTile(TileTypes type, int EdgeDistanceX,int EdgeDistanceY, int nrOfPasses);

private:

	void CreateBorder();
	void CreateDirt();
	void CreateStone();
	void CreateWater();
	void CreatePaths();
	Tile m_tiles[MAPHEIGHT][MAPWIDTH];
	TileTypes m_RandomMap[MAPHEIGHT][MAPWIDTH];
};