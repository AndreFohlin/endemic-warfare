#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "RenderWindow.h"

class Engine
{
public:
	Engine(void);
	~Engine(void);

	void Init(int width, int height, char* name);
	void Render();
	void Update();
	bool IsRunning(){return Running;}
private:
	Game*		m_Game;
	sf::RenderWindow m_renderWindow;
	bool Running;
};