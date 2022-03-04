#include "Engine.h"
#include <./sdl/SDL.h>
#include "InputManager.h"
#include "TimeManager.h"
#include "SoundManager.h"

Engine::Engine(void)
{
	m_Game = NULL;
}

Engine::~Engine(void)
{
}

void Engine::Init(int width, int height, char* name)
{
	// -Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// -Set Win Name
	SDL_WM_SetCaption("Endemic Warfare",NULL);

	//m_renderWindow.Create(sf::VideoMode(width, height, 32), name,sf::Window::Fixed);
	RenderWindow::Instance()->SetRenderWindow(NULL);
	m_Game = new Game();
	m_Game->Init();
	//m_renderWindow.UseVerticalSync(true);
	TimeManager::Instance()->Init();
	SoundManager::Instance()->Init();
	
}

void Engine::Render()
{
	//Render game
	m_Game->Render();

	//Show on screen
	RenderWindow::Instance()->Display();
}

void Engine::Update()
{
	TimeManager::Instance()->Update();

	InputManager::Instance()->Update();	

	if(InputManager::Instance()->getKey(1))
	{
		Running = false;
	}

	m_Game->Update();
	//
	//Update game
	//
}