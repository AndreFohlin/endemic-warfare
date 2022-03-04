#pragma once
#include "GameObject.h"
#include "NPCTypes.h"
#include "Animation.h"
#include "TimeManager.h"
class Player;

class AIDigger : public GameObject
{

public:
	AIDigger();
	~AIDigger();
	void Update(Player* player);
	void Render();
	void Create(float startX, float startY, int id, NPCTypes npcType);
	void Kill();

	const int GetXIndex() {return m_xindex;}
	const int GetYIndex() {return m_yindex;}

	const int GetID() {return m_id;}

private:
	void setStartPosition(float x, float y);
	void GetNewTarget();

	void Respawn();

	int m_id;
	int m_xindex;
	int m_yindex;
	int m_TargetX;
	int m_TargetY;
	
	POINT m_Dir;
	bool m_killed;
	float m_Speed;
	NPCTypes m_Type;

	SDL_Surface*		m_SurfaceBlood;

	//Animation
	AnimationManager	m_animation;

	sf::Clock			m_bloodClock;
	float				m_bloodTimer;
};