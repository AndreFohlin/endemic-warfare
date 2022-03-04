#include "GameStates.h"
#include "Game.h"
#include "InputManager.h"

#define IM InputManager::Instance()

MenuState* MenuState::Instance()
{
  static MenuState instance;

  return &instance;
}

void MenuState::Enter(Game* game)
{
}


void MenuState::Update(Game* game)
{
	//game->m_tm2.Update();
	if(InputManager::Instance()->getKey(28))
	{
		game->GetStateMachine()->ChangeState(PlayState::Instance());
	}
	
	bool b = true;
}

void MenuState::Render(Game* game)
{
	//game->m_tm2.Render();
}

void MenuState::Exit(Game* game)
{
}