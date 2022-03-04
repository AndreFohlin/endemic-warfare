#include "ScoreManager.h"



ScoreManager::ScoreManager()
{
	m_PlayerScore = 0;
	m_Gold =0;
	m_Kills  = 0;
	m_Mead = 0;
	m_Women = 0;
}
void ScoreManager::ResetMultiplier()
{
	m_Gold =0;
	m_Kills  = 0;
	m_Mead = 0;
	m_Women = 0;
}

void ScoreManager::AddScore(int score, ScoreType type)
{
	if(type == GOLD)
	{
		m_Gold+=1;
		m_PlayerScore += (m_Gold * 1.1f) * score;
	}
	else if(type == MEAD)
	{
		m_Mead+=1;
		m_PlayerScore += (m_Mead * 1.1f) * score;
	}
	else if(type == WOMEN)
	{
		m_Women+=1;
		m_PlayerScore += (m_Women * 1.1f) * score;
	}
	else if(type == BOMB)
	{
		//m_Bomb+=1;
		//m_PlayerScore += (m_Bomb * 1.1f) * score;
	}
}