#include "TileManager.h"
#include "RenderWindow.h"
#include <time.h>
#include <math.h>

#define RW RenderWindow::Instance()->GetRenderWindow()

TileManager::TileManager(void)
{
}
TileManager::~TileManager(void)
{
}

void TileManager::InitTiles(sf::Image* tilemap,unsigned int tileheight, unsigned int tilewidth) 
{

	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			Tile t;
			t.Init();
			t.SetX(float(x*tilewidth));
			t.SetY(float(y*tileheight));
			t.SetIndex(x,y);
			t.SetType(WATER);
			m_tiles[y][x] = t;
		}
	}
	CreateDirt();
	CreateStone();
	CreatePaths();
	CreateWater();
	CreateBorder();
}


void TileManager::Render()
{
	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			m_tiles[y][x].Render();
		}
	}
}


void TileManager::CreateBorder()
{
	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			if(x == 0 || x == 63 || y == 0 || y == 39)
			{
				m_tiles[y][x].SetType(CRYSTAL);
			}
		}
	}
}

void TileManager::CreateDirt()
{
	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			if(!(x == -1 || x == 64 ||y == -1 || y == 40))
			{
				m_tiles[y][x].SetType(DIRT);
			}
		}
	}
	SpreadTile(DIRT,0,0,1);
}

void TileManager::CreateStone()
{

	int EdgeDistanceX = 0;
	int EdgeDistanceY = 0;
	int nrOfPasses = 25;

	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			if((x == 1 || x == 62 ||y == 1 || y == 38))
			{
				m_tiles[y][x].SetType(STONE);
			}
		}
	}
	SpreadTile(STONE,EdgeDistanceX,EdgeDistanceY,nrOfPasses);



}


void TileManager::CreateWater()
{

	srand(time(NULL));

	int EdgeDistanceX = 1;
	int EdgeDistanceY = 1;
	int nrOfPasses = 10;


/*
	//(Random Lake Generation)
	
	EdgeDistanceX	= 5;
	EdgeDistanceY	= 5;
	nrOfPasses		= 20;

	//for(int i = 0; i < 3; i++)
	//{
	m_tiles[rand()%20+10][rand()%40+10].SetType(WATER);
	m_tiles[rand()%20+10][rand()%40+10].SetType(WATER);
	m_tiles[rand()%20+10][rand()%40+10].SetType(WATER);
	//}
*/	

	//for(int i = 0; i < 3; i++)
	//{


	//River Generation
	int CurrentY	= 20;
	EdgeDistanceX	= 1;
	EdgeDistanceY	= 1;

	int BaseTileEdgeDistanceX	= 5;
	int BaseTileEdgeDistanceY	= 5;


	nrOfPasses		= 10;

	for(int i = 0; i < 63; i++)
	{
		switch(rand()%2)
		{
		case 0:
			if(!(CurrentY+1 == 63-BaseTileEdgeDistanceX))
			{
				CurrentY+=1;
			}
			break;

		case 1:
			if(!(CurrentY-1 == BaseTileEdgeDistanceY))
			{
				CurrentY-=1;
			}
			break;

		};
		if(CurrentY+1 != 40)
		{
			m_tiles[CurrentY+1][i].SetType(WATER);
		}
		m_tiles[CurrentY][i].SetType(WATER);
		
	}
	//}

	SpreadTile(WATER,0,0,4);
}


void TileManager::CreatePaths()
{
	int nrOfLines = 7;
	int nrOfPasses	= 10;
	int EdgeDistanceX	= 8;
	int EdgeDistanceY	= 6;

	int StartX = 64/2;
	int StartY = 40/2;

	int EndX;
	int EndY;

	float dirx;
	float diry;

	for(int i = 0; i < nrOfLines; i++)
	{
		EndX = rand()%(63-EdgeDistanceX*2) +EdgeDistanceX;
		EndY = rand()%(39-EdgeDistanceY*2) +EdgeDistanceY;
		dirx = EndX - StartX;
		diry = EndY - StartY;
		float normlength = 1/ sqrt(float((dirx*dirx) + (diry*diry)));
		dirx *= normlength;
		diry *= normlength;

		float currentX = StartX;
		float currentY = StartY;


		while((int(currentX) != EndX && int(currentY) != EndY))
		{
			currentX +=dirx;
			currentY +=diry;
			m_tiles[int(currentY)][int(currentX)].SetType(SAND);
			m_tiles[int(currentY)][int(currentX+1)].SetType(SAND);

		}
	}
	SpreadTile(SAND,1,1,1);
}

void TileManager::SpreadTile(TileTypes type, int EdgeDistanceX,int EdgeDistanceY, int nrOfPasses)
{
	for(int i = 0; i < nrOfPasses; i++)
	{
		for(int y = 0; y < MAPHEIGHT; y++)
		{
			for(int x = 0; x < MAPWIDTH; x++)
			{
				if((x >= EdgeDistanceX || x <= 63 -EdgeDistanceX ||y >= EdgeDistanceY || y <= 39 -EdgeDistanceY))
				{
					if(y != -1 || x != -1 || y != 40 || x != 64)
					{
						if( m_tiles[y-1][x].GetType() == type)
						{
							switch(rand() % 10)
							{
							case 1:
								m_tiles[y][x].SetType(type);
								break;
							};
						}
					}
					if(y != -1 || x != -1 || y != 40 || x != 64)
					{
						if( m_tiles[y+1][x].GetType() == type)
						{
							switch(rand() % 10)
							{
							case 1:
								m_tiles[y][x].SetType(type);
								break;
							};
						}
					}
					if( m_tiles[y][x-1].GetType() == type)
						if(y != -1 || x != -1 || y != 40 || x != 64)
						{
							{
								switch(rand() % 10)
								{
								case 1:
									m_tiles[y][x].SetType(type);
									break;
								};
							}
						}
						if(y != -1 || x != -1 || y != 40 || x != 64)
						{
							if( m_tiles[y][x+1].GetType() == type)
							{
								switch(rand() % 10)
								{
								case 1:
									m_tiles[y][x].SetType(type);
									break;
								};
							}
						}
				}
			}
		}
	} 
}





Tile* TileManager::GetTile(unsigned int x, unsigned int y)
{
	return &m_tiles[y][x];
}

Tile* TileManager::GetTileFromPosition(float x, float y)
{
	int xi = (int)x/16;
	int yi = (int)y/16;

	return &m_tiles[(int)y/16][(int)x/16];
}

void TileManager::Update()
{
	for(int y = 0; y < MAPHEIGHT; y++)
	{
		for(int x = 0; x < MAPWIDTH; x++)
		{
			m_tiles[y][x].Update();
		}
	}
}