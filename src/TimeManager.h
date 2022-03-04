#pragma once
#include <./sdl/SDL.h>

class TimeManager
{
public:

	static TimeManager* Instance();
	void Init();
	void Update();
	float getDelta();

private:
	TimeManager();
	TimeManager(const TimeManager&);
	TimeManager& operator=(const TimeManager&);
	int m_LastTime;
	float m_delta;
};
