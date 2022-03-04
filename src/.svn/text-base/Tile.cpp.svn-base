#include "Tile.h"
#include "ResourceManager.h"
#include "RenderWindow.h"
#include "ExplosionManager.h"

#define RM ResourceManager::Instance()
#define EM ExplosionManager::Instance()

Tile::Tile(void)
{
	m_TileID = 0;
	GameObject::GameObject();
}

Tile::~Tile(void)
{
	GameObject::~GameObject();
}

void Tile::Init()
{
	m_walkSpeed = 1.0f;
	GameObject::Init();
}

void Tile::CleanUp()
{
	GameObject::CleanUp();
}

void Tile::Update()
{
	//Update animation
	GameObject::Update();
}

void Tile::Render()
{
	GameObject::Render();
}

void Tile::SetWalkable(bool isWalkable)
{
	m_walkable = isWalkable;
}

sf::IntRect Tile::GetRect()
{
	sf::IntRect newRect(m_X, m_Y, m_X + 16, m_Y + 16);

	return newRect;
}


void Tile::SetType(TileTypes type)
{
	m_oldType = m_type;

	switch(type)
	{
	case NONE:
		SetWalkable(true);
		SetSprite("../data/graphics/bomb_super.bmp");
		SetLife(0.2f);
		SetPressureDMG(0.0f);
		SetDestroyAble(true);
		SetWalkSpeed(1.0f);
		break;
	case CRYSTAL:
		SetWalkable(false);
		SetSprite("../data/graphics/Dimond.bmp");
		SetLife(0.2f);
		SetDestroyAble(false);
		SetWalkSpeed(0.0f);
		break;
	case GRASS:
		SetWalkable(true);
		SetSprite("../data/graphics/grass2.bmp");
		SetLife(0.2f);
		SetPressureDMG(20.0f);
		SetWalkSpeed(1.5f);
		SetDestroyAble(true);
		break;
	case DIRT:
		SetWalkable(false);
		SetSprite("../data/graphics/dirt2.bmp");
		SetLife(0.2f);
		SetPressureDMG(100.0f);
		SetWalkSpeed(1.0f);
		SetDestroyAble(true);
		break;
	case STONE:
		SetWalkable(false);
		SetSprite("../data/graphics/stone.bmp");
		SetLife(0.6f);
		SetPressureDMG(100.0f);
		SetWalkSpeed(1.0f);
		SetDestroyAble(true);
		break;
	case FIRE:
		SetWalkable(false);
		SetSprite("../data/graphics/dirt2.bmp");
		SetLife(0.2f);
		SetPressureDMG(20.0f);
		SetWalkSpeed(1.0f);
		SetDestroyAble(false);
		break;
	case WATER:
		SetWalkable(true);
		SetSprite("../data/graphics/water.bmp");
		SetLife(0.2f);
		SetPressureDMG(100.0f);
		SetWalkSpeed(0.5f);
		SetDestroyAble(false);
		break;
	case SAND:
		SetWalkable(true);
		SetSprite("../data/graphics/sand2.bmp");
		SetLife(0.2f);
		SetPressureDMG(20.0f);
		SetWalkSpeed(1.0f);
		SetDestroyAble(true);
		break;
	case DESTROYED:
		SetWalkable(true);
		SetSprite("../data/graphics/destroyed.bmp");
		SetLife(0.2f);
		SetPressureDMG(20.0f);
		SetDestroyAble(true);
		SetWalkSpeed(1.0f);
		break;
	case WALL:
		SetWalkable(false);
		SetSprite("../data/graphics/WALL.bmp");
		SetLife(0.4f);
		SetDestroyAble(true);
		SetWalkSpeed(1.0f);
		break;
	case METAL:
		SetWalkable(true);
		SetSprite("../data/graphics/Metal.bmp");
		SetLife(1.0f);
		SetDestroyAble(false);
		SetWalkSpeed(1.0f);
		break;
	default:
		break;
	}

	m_type = type;
}

void Tile::DecreaseLife(float decLife)
{
	if(m_destroyAble)
	{
		m_life -= decLife;
	}
}

void Tile::ExplodeTo(TileTypes type)
{
	SetType(type);
}

int Tile::GetXIndex()
{
	return m_indexX;
}

int Tile::GetYIndex()
{
	return m_indexY;
}