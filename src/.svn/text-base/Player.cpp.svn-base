#include "Player.h"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "LevelManager.h"
#include <./sdl/SDL.h>
#include "InputManager.h"
#include "BombManager.h"
#include "CollisionManager.h"
#include "ExplosionManager.h"
#include "OcclusionManager.h"
#include "SoundManager.h"

// -Get Managers
#define RM ResourceManager::Instance()
#define RW RenderWindow::Instance()->GetRenderWindow()
#define LM LevelManager::Instance()
#define CM CollisionManager::Instance()
#define BM BombManager::Instance()
#define EM ExplosionManager::Instance()
#define SM SoundManager::Instance()


Player::Player()
{
	GameObject::GameObject();
	m_Clock.Reset();

	m_speed = 50;
	m_NrOfBombs = 10;
	m_cooldownTime = 0.0f;
	m_bombCooldown.Reset();
	m_life = 100.0f;

	m_bloodTimer = 0.0f;
	m_bloodClock.Reset();
	m_killed = false;
}

Player::~Player()
{

}

void Player::Update()
{	
	
	float delta = m_Clock.GetElapsedTime();

	//Update animation
	m_animation.Update(delta, m_X, m_Y);

	if(m_killed)
	{
		m_bloodTimer = m_bloodClock.GetElapsedTime();

		if(m_bloodTimer >= 3.0f)
		{
			m_life = 100.0f;
			SetX(32*16);
			SetY(20*16);
			CM->GetTile(m_X, m_Y)->SetType(SAND);
			m_animation.ChangeAnimation("test");
			m_killed = false;
		}
	}
	else
	{
		if(m_life <= 0)
		{
			
			this->Kill();
		}

		Tile* m_currentTile = CM->GetTile(m_X, m_Y);

		Tile* collisionTile;

		// -Check Collision Y-
		if(InputManager::Instance()->getKey(72))
		{
			POINT dir;
			dir.y = -1;
			dir.x = 0;

			if(!CM->CheckCollision(m_X + 4, m_Y + 4, dir)) 
			{
				m_Y -= (m_speed * delta) * CM->GetTile(m_X, m_Y)->GetWalkSpeed();
			}
			else
			{
				collisionTile = CM->GetTile(m_X + 4, m_Y - 8);

				if(collisionTile->GetDestroyAble())
				{
					if(collisionTile->GetLife() <= 0)
					{
						collisionTile->SetType(SAND);
					}
					else
					{
						collisionTile->DecreaseLife(delta);
					}
				}
			}
		}

		// -Check Collision Y+
		if(InputManager::Instance()->getKey(80))
		{
			POINT dir;
			dir.y = 1;
			dir.x = 0;

			if(!CM->CheckCollision(m_X + 4, m_Y + 4, dir))
			{
				m_Y += (m_speed * delta) * CM->GetTile(m_X, m_Y)->GetWalkSpeed();
			}
			else
			{
				collisionTile = CM->GetTile(m_X + 4, m_Y + 8);

				if(collisionTile->GetDestroyAble())
				{
					if(collisionTile->GetLife() <= 0)
					{
						collisionTile->SetType(SAND);
					}
					else
					{
						collisionTile->DecreaseLife(delta);
					}
				}
			}
		}

		// -Check Collision X-
		if(InputManager::Instance()->getKey(75))
		{
			POINT dir;
			dir.x = -1;
			dir.y = 0;

			if(!CM->CheckCollision(m_X + 4, m_Y + 4, dir))
			{
				m_X -= (m_speed * delta) * CM->GetTile(m_X, m_Y)->GetWalkSpeed();
			}
			else
			{
				collisionTile = CM->GetTile(m_X - 8, m_Y + 4);

				if(collisionTile->GetDestroyAble())
				{
					if(collisionTile->GetLife() <= 0)
					{
						collisionTile->SetType(SAND);
					}
					else
					{
						collisionTile->DecreaseLife(delta);
					}
				}
			}
		}

		// -Check Collision X+
		if(InputManager::Instance()->getKey(77))
		{
			POINT dir;
			dir.x = 1;
			dir.y = 0;

			if(!CM->CheckCollision(m_X + 4, m_Y + 4, dir))
			{
				m_X += (m_speed * delta) * CM->GetTile(m_X, m_Y)->GetWalkSpeed();
				collisionTile = NULL;
			}
			else
			{
				collisionTile = CM->GetTile(m_X + 8, m_Y  + 4);

				if(collisionTile->GetDestroyAble())
				{
					if(collisionTile->GetLife() <= 0)
					{
						collisionTile->SetType(SAND);
					}
					else
					{
						collisionTile->DecreaseLife(delta);
					}
				}
			}
		}

		m_cooldownTime = m_bombCooldown.GetElapsedTime();
		if(m_cooldownTime >= 0.2f)
		{
			if(InputManager::Instance()->getKey(57))
			{
				//Add a bomb to the manager if we have bombs
				if(GetNrOfBombs() > 0)
				{
					TileManager* hej = LM->GetActiveLevel()->GetTileManager();
					BM->Add(hej->GetTileFromPosition(m_X+4, m_Y+4)->GetXIndex(), hej->GetTileFromPosition(m_X+4, m_Y+4)->GetYIndex(), MEDIUM);
				}
				// ...and remove from the stash
				RemoveBombs(1);
			}
			
			// ...and remove from the stash
			m_bombCooldown.Reset();

		}

		if(InputManager::Instance()->getKey(34))
		{
			BM->Add(m_X+4, m_Y+4, BIG);
		}

		m_Clock.Reset();
		
	}

	GameObject::Update();
	OcclusionManager::Instance()->Show(m_X,m_Y);
}
void Player::Render()
{
	m_animation.Render();
	//GameObject::Render();
}

void Player::Init()
{
	//m_animation.SetSpriteMap(ResourceManager::Instance()->getSurface("../data/graphics/viking.bmp"));
	Animation a;
	a.height = a.width = 16;
	a.nframes = 3;
	a.startx = 0;
	a.starty = 0;
	a.offsetx = 4;
	a.offsety = 8;
	a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/viking.bmp");
	m_animation.AddAnimation(a, "test");

	//m_animation.SetSpriteMap(ResourceManager::Instance()->getSurface("../data/graphics/blood.bmp"));
	a.height = a.width = 16;
	a.nframes = 1;
	a.startx = 0;
	a.starty = 0;
	a.offsetx = 0;
	a.offsety = 0;
	a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/blood.bmp");
	m_animation.AddAnimation(a, "blood");

	m_animation.ChangeAnimation("test");

	GameObject::Init();
}

void Player::CleanUp()
{
}

void Player::AddBombs(int bombs)
{
	//Add bombs to the bombstock
	m_NrOfBombs += bombs;
}

void Player::RemoveBombs(int bombs)
{
	m_NrOfBombs -= bombs;
	if(m_NrOfBombs < 0)
	{
		m_NrOfBombs = 0;
	}
}

int Player::GetNrOfBombs()
{
	return m_NrOfBombs;
}

void Player::Kill()
{
	//m_animation.SetSpriteMap(RM->getSurface("../data/graphics/blood.bmp"));
	m_animation.ChangeAnimation("blood");
	m_bloodClock.Reset();
	m_killed = true;
}