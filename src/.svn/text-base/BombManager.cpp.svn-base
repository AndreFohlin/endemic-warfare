#include "BombManager.h"

BombManager* BombManager::Instance()
{
	static BombManager instance;

	return &instance;
}

void BombManager::Render()
{
	int bombSize = m_bombVector.size();
	for(int i = 0; i < bombSize; i++)
	{
		m_bombVector[i].Render();
	}
}

void BombManager::Update()
{
	int bombSize = m_bombVector.size();
	for(int i = 0; i < bombSize; i++)
	{
		m_bombVector[i].Update();
	}
}

void BombManager::Add(int tileXindex, int tileYindex, BombTypes types)
{
	Bomb m_bomb;

	m_bomb.Create(tileXindex, tileYindex, types, m_bombVector.size());

	m_bombVector.push_back(m_bomb);
}

void BombManager::Delete(int id)
{
	std::vector<Bomb>::iterator iter;
	iter = m_bombVector.begin();
	int bombSize = m_bombVector.size();
	for(int i = 0; i < bombSize; i ++)
	{
		if(m_bombVector[i].GetID() == id)
		{
			m_bombVector.erase(iter);
			return;
		}
		if(m_bombVector.size())
		{
		iter++;
		}
	}
}

Bomb* BombManager::CheckCollision(float xPos, float yPos)
{
	int bombSize = m_bombVector.size();
	for(int i = 0; i < bombSize; i++)
	{
		if(m_bombVector[i].CheckCollision(xPos, yPos))
		{
			return &m_bombVector[i];
		}
	}
	return NULL;
}