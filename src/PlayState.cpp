#include "GameStates.h"
#include "Game.h"
#include "Player.h"
#include "RenderWindow.h"
#include "BombManager.h"
#include "ExplosionManager.h"

#define RW RenderWindow::Instance()->GetRenderWindow()
#define BM BombManager::Instance()
#define EM ExplosionManager::Instance()

PlayState* PlayState::Instance()
{
  static PlayState instance;

  return &instance;
}

void PlayState::Enter(Game* game)
{
	//Reset the timer in the HUD so the time will start correct
	game->GetHUD()->m_Clock.Reset();
	game->GetHUD()->SetTime(0,10);
}

void PlayState::Update(Game* game)
{

	game->GetLevelManager()->Update();

	BM->Update();
	EM->Update();
	game->GetHUD()->Render(LevelManager::Instance()->GetActiveLevel()->GetPlayer());
	
	//game->GetTileManager()->Update();
/*	if(RW->GetInput().IsMouseButtonDown(sf::Mouse::Right))
	{
		game->GetStateMachine()->ChangeState(MenuState::Instance());
	}
	*/
}

void PlayState::Render(Game* game)
{
	game->GetLevelManager()->Render();

	BM->Render();
	EM->Render();
	game->GetHUD()->Update();
}

void PlayState::Exit(Game* game)
{
}
