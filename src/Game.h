#pragma once

#include "StateMachine.h"
#include <SFML\Graphics.hpp>
#include "LevelManager.h"
#include "HUD.h"

class Game
{
public:
	Game(void);
	~Game(void);

	void					Init();
	void					Render();
	void					Update();

	StateMachine<Game>*		GetStateMachine(){return m_stateMachine;}
	
	LevelManager*	GetLevelManager() {return LevelManager::Instance();}
	HUD*			GetHUD(){return &m_hud;}
	void			RenderScoreScreen();
private:

	StateMachine<Game>*	m_stateMachine;
	// -MenuStatevariables
	GameObject	m_splash;
	
	// -PlayStatevariables
	HUD	m_hud;

	// -ScoreStatevariables
	GameObject	m_scoreback;
};