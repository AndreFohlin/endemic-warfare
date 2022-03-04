#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <./sdl/sdl.h>

class RenderWindow
{
private:
	RenderWindow(){}

	RenderWindow(const RenderWindow&);
	RenderWindow& operator=(const RenderWindow&);

public:

	static RenderWindow* Instance();

	SDL_Surface*			GetRenderWindow()	{return m_Screen;}
	void					SetRenderWindow(sf::RenderWindow* renderwindow);
	void					Display();
	SDL_Surface* m_Screen;
	sf::RenderWindow*		m_RenderWindow;
};