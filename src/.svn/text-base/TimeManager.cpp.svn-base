#include "TimeManager.h"

TimeManager::TimeManager()
{
	m_LastTime = -0;

}

void TimeManager::Init()
{
	m_LastTime = SDL_GetTicks();
	m_delta = 0;

}

void TimeManager::Update()
{
	int newtime = SDL_GetTicks();
	m_delta = float(newtime -m_LastTime)*0.001f;
	if(m_delta > 0.16f)
	{
		m_delta = 0.16f;
	}
}

float TimeManager::getDelta()
{
	return m_delta;
}

TimeManager* TimeManager::Instance()
{
	static TimeManager instance;
	return &instance;
};