#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "ResourceManager.h"
#include "RenderWindow.h"
#include "BombTypes.h"

class Bomb
{
public:
	Bomb(void);
	~Bomb(void);

	void Create(int tileXindex, int tileYindex,BombTypes types, int id);
	void Update();
	void Render();

	const float GetX() {return m_X;}
	const float GetY() {return m_Y;}

	const bool CheckCollision(float x, float y);

	int GetID(){return m_id;}
	void	Explode(bool test);
private:

	void	SetSprite(std::string name);
	

	void	SetPos(float x, float y);

	int m_tileXpos, m_tileYpos;
	float m_X, m_Y;
	
	sf::Sprite			m_Sprite;
	SDL_Surface*		m_Surface;

	BombTypes m_type;

	sf::Clock ExplodeClock;
	float ExplodeTime;
	int m_id;

	bool m_selfDestruct;
	bool m_stopRender;

};
