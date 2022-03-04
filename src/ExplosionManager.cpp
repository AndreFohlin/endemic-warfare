#include "ExplosionManager.h"

ExplosionManager* ExplosionManager::Instance()
{
	static ExplosionManager instance;

	return &instance;
}

void ExplosionManager::Render()
{
	int expSize = m_explosionVector.size();
	for(int i = 0; i < expSize; i++)
	{
		m_explosionVector[i].Render();
	}
}

void ExplosionManager::Update()
{
	int expSize = m_explosionVector.size();
	for(int i = 0; i < expSize; i++)
	{
		m_explosionVector[i].Update();
	}
}

void ExplosionManager::Add(int tileXindex, int tileYindex, bool self, POINT dir)
{
	Explosion m_explosion;

	m_explosion.Create(tileXindex, tileYindex, m_explosionVector.size(), self, dir);

	m_explosionVector.push_back(m_explosion);
}

void ExplosionManager::Delete(int id)
{
	std::vector<Explosion>::iterator iter;
	iter = m_explosionVector.begin();
	int expSize = m_explosionVector.size();
	for(int i = 0; i < expSize; i ++)
	{
		if(m_explosionVector[i].GetID() == id)
		{
			m_explosionVector.erase(iter);
			return;
		}
		if(m_explosionVector.size())
		{
		iter++;
		}
	}
}