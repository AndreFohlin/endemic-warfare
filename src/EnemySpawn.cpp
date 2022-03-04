#include "EnemySpawn.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "LevelManager.h"
#include <./sdl/SDL.h>
#include "InputManager.h"
#include "ExplosionManager.h"
#include "SoundManager.h"
#include "TimeManager.h"
#include "CollisionManager.h"

// -Get Managers
#define RM ResourceManager::Instance()
#define RW RenderWindow::Instance()->GetRenderWindow()
#define LM LevelManager::Instance()
#define CM CollisionManager::Instance()
#define BM BombManager::Instance()
#define EM ExplosionManager::Instance()
#define SM SoundManager::Instance()

EnemySpawn::EnemySpawn()
{

}

EnemySpawn::~EnemySpawn()
{

}
void EnemySpawn::Init(float xPos, float yPos)
{
	m_xpos = xPos;
	m_ypos = yPos;

	int x = int(xPos / 16);
	int y = int(yPos / 16);

	m_xIndex = x;
	m_yIndex = y;

	SetX(LM->GetActiveLevel()->GetTileManager()->GetTile(x,y)->GetX());
	SetY(LM->GetActiveLevel()->GetTileManager()->GetTile(x,y)->GetY());

	//m_animation.SetSpriteMap(ResourceManager::Instance()->getSurface("../data/graphics/viking.bmp"));
	Animation a;
	a.height = a.width = 16;
	a.nframes = 4;
	a.startx = 0;
	a.starty = 0;
	a.offsetx = 0;
	a.offsety = 0;
	a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/enemyteleport.bmp");
	m_AnimationManager.AddAnimation(a, "Animation");
	m_AnimationManager.ChangeAnimation("Animation");

//	GameObject::Init();

	//int x = xPos / 16;
	//int y = yPos / 16;

	//m_xIndex = x;
	//m_yIndex = y;

	SetX(float(x));
	SetY(float(y));
}

void EnemySpawn::Update()
{
	/*
	m_AnimationManager.Update(TimeManager::Instance()->getDelta(),m_X,m_Y);

	TileManager* m_tm = LM->GetActiveLevel()->GetTileManager();

	int x = m_X / 16;
	int y = m_Y / 16;

	m_tm->GetTile(x,y)->SetType(METAL);

	for(int i = 0; i < 3; i ++)
	{
		m_tm->GetTile((x-1)+i,y-1)->SetType(METAL);
	}
	m_tm->GetTile(x-1,y)->SetType(METAL);
	m_tm->GetTile(x+1,y)->SetType(METAL);
	for(int i = 0; i < 3; i ++)
	{
		m_tm->GetTile((x-1)+i,y+1)->SetType(METAL);
	}
*/
	GameObject::Update();
}

void EnemySpawn::Render()
{
	m_AnimationManager.Render();

}

void EnemySpawn::CleanUp()
{

}