#include "NPCManager.h"

NPCManager* NPCManager::Instance()
{
	static NPCManager instance;

	return &instance;
}

void NPCManager::Render()
{
	for(unsigned int i = 0; i < m_diggerVector.size(); i++)
	{
		m_diggerVector[i].Render();
	}
}

void NPCManager::Update(Player* player)
{
	for(unsigned int i = 0; i < m_diggerVector.size(); i++)
	{
		m_diggerVector[i].Update(player);
	}
}

void NPCManager::Add(int tileXindex, int tileYindex, NPCTypes types)
{
	AIDigger m_digger;

	m_digger.Create(float(tileXindex), float(tileYindex), int(m_diggerVector.size()), types);

	m_diggerVector.push_back(m_digger);
}

void NPCManager::Delete(int id)
{
	std::vector<AIDigger>::iterator iter;
	iter = m_diggerVector.begin();
	for(unsigned int i = 0; i < m_diggerVector.size(); i ++)
	{
		if(m_diggerVector[i].GetID() == id)
		{
			m_diggerVector.erase(iter);
			return;
		}
		if(m_diggerVector.size())
		{
		iter++;
		}
	}
}