#pragma once

#include "GameObject.h"
#include "FontManager.h"
class Player;
class HUD
{
public:
	HUD(void);
	~HUD(void);

	void Init(float x, float y);
	void Render(Player* player);
	void Update();
	void SetTime(int minutes, int seconds = 0);
	bool IsTimeUp(){return m_timeIsUp;}
	
	
	sf::Clock m_Clock;
	

private:

	GameObject m_VikingPic1;
	GameObject m_VikingPic2;
	GameObject m_VikingPic3;
	GameObject m_VikingPic4;

	GameObject m_BombPic;
	GameObject m_GirlPic;
	GameObject m_back;
	
	
	//Time left
	int m_minutes;
	float m_seconds;
	bool m_timeIsUp;
};