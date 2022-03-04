#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "ResourceManager.h"
#include "RenderWindow.h"

class Player;
class Explosion
{
public:
	Explosion(void);
	~Explosion(void);

	void Create(int tileXindex, int tileYindex, int id, bool ifself, POINT dir);
	void Update();
	void Render();

	int	GetID()	{return m_id;}

	void Move();

private:

	void	SetSprite(std::string name);
	void	SetPos(float x, float y);

	int m_tileXpos, m_tileYpos;
	float m_X, m_Y;
	
	sf::Sprite			m_Sprite;
	SDL_Surface*		m_Surface;

	sf::Clock m_explodeClock;
	float m_explodeTime;

	float m_pressure;
	int m_id;

	bool m_explode;
	bool m_self;
	POINT m_direction;
	POINT m_startIndex;

	Player* m_player;

	int lastXindex, lastYindex;
};
