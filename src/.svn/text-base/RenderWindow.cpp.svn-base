#include "RenderWindow.h"

RenderWindow* RenderWindow::Instance()
{
	static RenderWindow instance;

	return &instance;
}

void RenderWindow::SetRenderWindow(sf::RenderWindow* renderwindow)
{
	//m_RenderWindow = renderwindow;

	m_Screen = SDL_SetVideoMode(1024, 768, 32, SDL_DOUBLEBUF);
}

void RenderWindow::Display()
{
	SDL_UpdateRect(m_Screen,0,0,0,0);
}