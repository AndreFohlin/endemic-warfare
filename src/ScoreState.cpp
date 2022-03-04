#include "GameStates.h"
#include "Game.h"
#include "Player.h"
#include "RenderWindow.h"
#include "BombManager.h"
#include "ExplosionManager.h"
#include "FontManager.h"
#include "ScoreManager.h"
#include "InputManager.h"


#define RW RenderWindow::Instance()->GetRenderWindow()
#define BM BombManager::Instance()
#define EM ExplosionManager::Instance()


ScoreState* ScoreState::Instance()
{
  static ScoreState instance;

  return &instance;
}

void ScoreState::Enter(Game* game)
{
	
}

void ScoreState::Update(Game* game)
{
}

void ScoreState::Render(Game* game)
{
	game->RenderScoreScreen();
	char buf[10];

	FontManager::Instance()->AddText("goth2", "Score:",400,200);
	//FM->AddText("goth1", "Score:",800,690);
	itoa(ScoreManager::Instance()->GetScore(),buf,10);
	FontManager::Instance()->AddText("goth2", buf,530,200);

	FontManager::Instance()->Render();
}

void ScoreState::Exit(Game* game)
{
}
