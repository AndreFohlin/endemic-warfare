#pragma once
#include "GameObject.h"
#include "Animation.h"
class Player;

class Item : public GameObject
{
public:
	Item();
	~Item();

	void	Init(int type);
	void	Update(Player* player);
	void	CleanUp();
	void	Render();

	bool	IsActivated(){return m_activated;}

private:
	bool m_activated;
	int type;

	AnimationManager	m_animation;
};