#include "Explosion.h"
#include "RenderWindow.h"
#include "CollisionManager.h"
#include "TileManager.h"
#include "LevelManager.h"
#include "TimeManager.h"
#include "ExplosionManager.h"
#include "BombManager.h"
#include "ResourceManager.h"
#include "OcclusionManager.h"
#include "Player.h"
#include "math.h"

#define CM CollisionManager::Instance()
#define LM LevelManager::Instance()
#define TM TimeManager::Instance()
#define EM ExplosionManager::Instance()
#define BM BombManager::Instance()
#define RM ResourceManager::Instance()
#define OM OcclusionManager::Instance()

Explosion::Explosion(void)
{
	m_explode = true;
	m_explodeTime = 0.0f;
	m_pressure = 100.0f;
}

Explosion::~Explosion(void)
{
}

void Explosion::Create(int tileXindex, int tileYindex, int id, bool ifself, POINT dir)
{
	m_startIndex.x = tileXindex;
	m_startIndex.y = tileYindex;
	m_id = id;
	m_self = ifself;
	m_direction = dir;
	SetPos(tileXindex,tileYindex);
	SetSprite("../data/graphics/explode.bmp");
	m_explode = true;
	m_explodeClock.Reset();
}

void Explosion::Update()
{	
	m_player = LM->GetActiveLevel()->GetPlayer();

	m_explodeTime = m_explodeClock.GetElapsedTime();
	if(m_explodeTime > 1.0f)
	{
		if(m_pressure <= 0)
		{
			m_explode = false;
			EM->Delete(m_id);
		}
	}

	float vecX = (m_player->GetX()+4) - m_X+4;
	float vecY = (m_player->GetY()+4) - m_Y+4;

	float veclength = sqrt(vecX*vecX + vecY*vecY);

	veclength = abs(veclength);

	if(veclength < 15.0f)
	{
		m_player->DecreaseLife(100.0f);
	}

	POINT nullDir;
	nullDir.x = 0;
	nullDir.y = 0;

	TileManager* tm = LM->GetActiveLevel()->GetTileManager();
	if(tm->GetTileFromPosition(m_X + (m_direction.x * 16), m_Y + (m_direction.y * 16))->GetDestroyAble())
	{
		if(CM->GetTile(m_X,m_Y)->GetOldType() == DIRT)
		{
			m_pressure -= CM->GetTile(m_X,m_Y)->GetPressureDMG();
			OM->ShowTile(CM->GetTile(m_X,m_Y)->GetXIndex(), CM->GetTile(m_X,m_Y)->GetYIndex());
		}

		m_pressure -= CM->GetTile(m_X,m_Y)->GetPressureDMG();
		
		LM->GetEnemyCollision(m_X, m_Y);
		CM->GetTile(m_X,m_Y)->SetType(DESTROYED);
		OM->ShowTile(CM->GetTile(m_X,m_Y)->GetXIndex(), CM->GetTile(m_X,m_Y)->GetYIndex());

		lastXindex = CM->GetTile(m_X,m_Y)->GetXIndex();
		lastYindex = CM->GetTile(m_X,m_Y)->GetYIndex();

		if(m_pressure > 0)
		{
			Move();
		}
	}
	else
	{
		LM->GetEnemyCollision(m_X, m_Y);
		CM->GetTile(m_X,m_Y)->SetType(DESTROYED);
		m_pressure -= 100;
	}


	// -Chain reactions
	if(m_self)
	{
		Bomb* CollBomb;

		if(!BM->CheckCollision(CM->GetTile(m_X,m_Y)->GetXIndex(),CM->GetTile(m_X,m_Y)->GetYIndex()))
		{
			CollBomb = NULL;
		}
		else
		{	
			CollBomb = BM->CheckCollision(CM->GetTile(m_X,m_Y)->GetXIndex(), CM->GetTile(m_X,m_Y)->GetYIndex());
			
			CollBomb->Explode(true);
		}

		LM->GetEnemyCollision(m_X, m_Y);
		CM->GetTile(m_X,m_Y)->SetType(DESTROYED);
		OM->ShowTile(CM->GetTile(m_X,m_Y)->GetXIndex(), CM->GetTile(m_X,m_Y)->GetYIndex());
	}
}

void Explosion::Render()
{
	if(m_explode)
	{
		SDL_Rect explosionRect;
		explosionRect.x = int(m_X);
		explosionRect.y = int(m_Y);
		SDL_BlitSurface(m_Surface, NULL, RenderWindow::Instance()->GetRenderWindow(), &explosionRect);
	}
}

void Explosion::SetSprite(std::string name)
{
	m_Surface = RM->getSurface(name.c_str());
}

void Explosion::SetPos(float x, float y)
{
	TileManager* tm = LM->GetActiveLevel()->GetTileManager();

	float xp = m_X;
	float yp = m_Y;

	m_X = tm->GetTileFromPosition(x,y)->GetX();
	m_Y = tm->GetTileFromPosition(x,y)->GetY();

	m_Sprite.SetLeft(m_X);
	m_Sprite.SetTop(m_Y);
}

void Explosion::Move()
{
	if(m_direction.x > 0 && m_direction.y == 0)
	{
		SetPos(m_X + 16, m_Y+16);
	}
	if(m_direction.x < 0 && m_direction.y == 0)
	{
		SetPos(m_X - 16, m_Y+16);
	}
	if(m_direction.y > 0 && m_direction.x == 0)
	{
		SetPos(m_X, m_Y + 16);
	}
	if(m_direction.y < 0 && m_direction.x == 0)
	{
		SetPos(m_X, m_Y - 16);
	}
	if(m_direction.x > 0 && m_direction.y < 0)
	{
		SetPos(m_X + 16, m_Y - 16);
	}
	if(m_direction.x > 0 && m_direction.y > 0)
	{
		SetPos(m_X + 16, m_Y + 16);
	}
	if(m_direction.x < 0 && m_direction.y > 0)
	{
		SetPos(m_X - 16, m_Y + 16);
	}
	if(m_direction.x < 0 && m_direction.y < 0)
	{
		SetPos(m_X - 16, m_Y - 16);
	}
	if(m_direction.x == 0 && m_direction.y == 0)
	{
		m_pressure = 0;
	}
}