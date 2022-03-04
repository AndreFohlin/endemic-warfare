#include "Bomb.h"
#include "RenderWindow.h"
#include "CollisionManager.h"
#include "TileManager.h"
#include "LevelManager.h"
#include "BombManager.h"
#include "ExplosionManager.h"
#include "ResourceManager.h"
#include "SoundManager.h"

#define SM SoundManager::Instance()
#define CM CollisionManager::Instance()
#define LM LevelManager::Instance()
#define EM ExplosionManager::Instance()
#define RM ResourceManager::Instance()

Bomb::Bomb(void)
{
	
}

Bomb::~Bomb(void)
{
}

void Bomb::Create(int tileXindex, int tileYindex, BombTypes types,int id)
{
	SetPos(tileXindex,tileYindex);

	ExplodeClock.Reset();
	ExplodeTime = 0.0f;

	m_id = id;

	switch(types)
	{
		case(SMALL):
			SetSprite("../data/graphics/bomb_small.bmp");
			m_type = SMALL;
			m_selfDestruct = true;
			break;
		case(MEDIUM):
			SetSprite("../data/graphics/bomb_medium.bmp");
			m_type = MEDIUM;
			m_selfDestruct = true;
			break;
		case(BIG):
			SetSprite("../data/graphics/bomb_big.bmp");
			m_type = BIG;
			m_selfDestruct = false;
			break;
		case(SUPER):
			SetSprite("../data/graphics/bomb_super.bmp");
			m_type = SUPER;
			m_selfDestruct = true;
			break;
	}

	if(LM->GetActiveLevel()->GetTileManager()->GetTile(tileXindex,tileYindex)->GetType() == WATER)
	{
		// -Play sound "plums"
		//BombManager::Instance()->Delete(m_id);
		//m_selfDestruct = false;
		//m_stopRender = true;
	}
}

void Bomb::Update()
{
	if(m_selfDestruct)
	{
		ExplodeTime = ExplodeClock.GetElapsedTime();

		if(ExplodeTime >= 2.0f)
		{
			Explode(false);
			BombManager::Instance()->Delete(m_id);
		}
	}
}

void Bomb::Render()
{
	SDL_Rect bombRect;
	bombRect.x = int(m_X);
	bombRect.y = int(m_Y);
	SDL_BlitSurface(m_Surface, NULL, RenderWindow::Instance()->GetRenderWindow(), &bombRect);
}

void Bomb::SetSprite(std::string name)
{
	m_Surface = RM->getSurface(name.c_str());
}

void Bomb::Explode(bool self)
{

	SM->PlaySound("Explosion",255);
	Tile* onTile = CollisionManager::Instance()->GetTile(m_X, m_Y);
	POINT dir;
	dir.x = 0;
	dir.y = 0;

	switch(m_type)
	{
		case(SMALL):

			break;
		case(MEDIUM):

			onTile->ExplodeTo(DESTROYED);
			EM->Add(onTile->GetX(), onTile->GetY(), self, dir);

			if(CollisionManager::Instance()->GetTile(m_X, m_Y-16))
			{
				if(CollisionManager::Instance()->GetTile(m_X, m_Y-16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X, m_Y-16);
					expTile->ExplodeTo(DESTROYED);
					dir.y = -1;
					dir.x = 0;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X+16, m_Y-16))
			{
				if(CollisionManager::Instance()->GetTile(m_X+16, m_Y-16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X+16, m_Y-16);
					expTile->ExplodeTo(DESTROYED);
					dir.x = 1;
					dir.y = -1;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X+16, m_Y))
			{
				if(CollisionManager::Instance()->GetTile(m_X+16, m_Y)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X+16, m_Y);
					expTile->ExplodeTo(DESTROYED);
					dir.x = 1;
					dir.y = 0;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X+16, m_Y+16))
			{
				if(CollisionManager::Instance()->GetTile(m_X+16, m_Y+16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X+16, m_Y+16);
					expTile->ExplodeTo(DESTROYED);
					dir.x = 1;
					dir.y = 1;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X, m_Y+16))
			{
				if(CollisionManager::Instance()->GetTile(m_X, m_Y+16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X, m_Y+16);
					expTile->ExplodeTo(DESTROYED);
					dir.y = 1;
					dir.x = 0;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X-16, m_Y+16))
			{
				if(CollisionManager::Instance()->GetTile(m_X-16, m_Y+16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X-16, m_Y+16);
					expTile->ExplodeTo(DESTROYED);
					dir.x = -1;
					dir.y = 1;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X-16, m_Y))
			{
				if(CollisionManager::Instance()->GetTile(m_X-16, m_Y)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X-16, m_Y);
					expTile->ExplodeTo(DESTROYED);
					dir.x = -1;
					dir.y = 0;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}

			if(CollisionManager::Instance()->GetTile(m_X-16, m_Y-16))
			{
				if(CollisionManager::Instance()->GetTile(m_X-16, m_Y-16)->GetDestroyAble())
				{
					Tile* expTile = CollisionManager::Instance()->GetTile(m_X-16, m_Y-16);
					expTile->ExplodeTo(DESTROYED);
					dir.x = -1;
					dir.y = -1;
					EM->Add(expTile->GetX(), expTile->GetY(),self, dir);
				}
			}
			break;
		case(BIG):
			break;
		case(SUPER):
			break;
	}
}

void Bomb::SetPos(float x, float y)
{
	TileManager* tm = LM->GetActiveLevel()->GetTileManager();

	m_X = tm->GetTile(x,y)->GetX();
	m_Y = tm->GetTile(x,y)->GetY();

	m_tileXpos = (int)x;
	m_tileYpos = (int)y;

	m_Sprite.SetLeft(m_X);
	m_Sprite.SetTop(m_Y);
}

const bool Bomb::CheckCollision(float x, float y)
{
	if(x == m_tileXpos && y == m_tileYpos)
	{
		return 1;
	}
	return 0;
}