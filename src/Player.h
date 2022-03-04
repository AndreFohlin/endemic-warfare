#pragma once
#include "GameObject.h"
#include "Animation.h"

namespace sf
{
	class Sprite;
	class Image;
	class RenderWindow;
}

class Player : public GameObject
{
public:
	Player(void);
	~Player(void);
	
	static Player*	Instance()
	{
		static Player instance;
		return &instance;
	}

	void Init();
	void Update();
	void Render();
	void CleanUp();

	const void	SetSpeed(float speed) {m_speed = speed;}
	float		GetSpeed(){return m_speed;}

	void		AddBombs(int bombs);
	void		RemoveBombs(int bombs);
	int			GetNrOfBombs();

	const float GetLife()				{return m_life;}
	void		SetLife(float life)		{m_life = life;}
	void		DecreaseLife(float life){m_life -= life;}

private:

	sf::Clock m_Clock;

	sf::Clock m_bombCooldown;
	float m_cooldownTime;

	float m_speed;

	//Nr of bombs
	int m_NrOfBombs; 

	// Animationobject
	AnimationManager m_animation;

	float m_life;

	void Kill();
	bool m_killed;

	sf::Clock			m_bloodClock;
	float				m_bloodTimer;
};