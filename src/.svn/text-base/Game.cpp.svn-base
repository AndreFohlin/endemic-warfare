#include "Game.h"
#include "GameStates.h"

#define LM LevelManager::Instance()

Game::Game(void)
{
	m_stateMachine = NULL;
}

Game::~Game(void)
{
	if(m_stateMachine)
	{
		delete m_stateMachine;
	}
}

void Game::Init()
{
	// -Create the statemachine for the game
	m_stateMachine = new StateMachine<Game>(this);

	// -Now load all the tiles from a bmp

	LM->AddLevel("../data/XML/Level1/level1.xml", "TestLevel1");
	//LM->AddLevel("../data/graphics/test1.bmp", "TestLevel2");
	LM->SetActiveLevel("TestLevel1");
	

	// -Set the current state to be the MenuState
	m_stateMachine->SetCurrentState(MenuState::Instance());

	// -Create the splash
	m_splash.Init();
	m_splash.SetSprite("../data/graphics/splash_screen.bmp");

	// -Create the scoresplash
	m_scoreback.Init();
	m_scoreback.SetSprite("../data/graphics/scoreback.bmp");

	//m_player.Create();

	// -HUD
	m_hud.Init(0,16*40);
	
}

void Game::Render()
{
	m_stateMachine->Render();
	
	//Show the splash if in 
	if(m_stateMachine->CurrentState() == MenuState::Instance())
	{
		m_splash.Render();
	}
}

void Game::Update()
{
	m_stateMachine->Update();
	

	

	if(m_hud.IsTimeUp())
	{
		m_stateMachine->ChangeState(ScoreState::Instance());
	}
}

void Game::RenderScoreScreen()
{
	m_scoreback.Render();
}