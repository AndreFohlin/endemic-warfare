#include "PlayerTeleporter.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "LevelManager.h"
#include <./sdl/SDL.h>
#include "InputManager.h"
#include "ExplosionManager.h"
#include "SoundManager.h"
#include "TimeManager.h"

// -Get Managers
#define RM ResourceManager::Instance()
#define RW RenderWindow::Instance()->GetRenderWindow()
#define LM LevelManager::Instance()
#define CM CollisionManager::Instance()
#define BM BombManager::Instance()
#define EM ExplosionManager::Instance()
#define SM SoundManager::Instance()


/*
class PlayerTeleporter : public GameObject
{
public:
PlayerTeleporter ();
~PlayerTeleporter ();
private:
AnimationManager m_AnimationManager;


};
*/

PlayerTeleporter::PlayerTeleporter()
{

}

PlayerTeleporter::~PlayerTeleporter()
{

}
void PlayerTeleporter::Init()
{
		//m_animation.SetSpriteMap(ResourceManager::Instance()->getSurface("../data/graphics/viking.bmp"));
	Animation a;
	a.height = a.width = 16;
	a.nframes = 4;
	a.startx = 0;
	a.starty = 0;
	a.offsetx = 0;
	a.offsety = 0;
	a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/PlayerTeleporter.bmp");
	m_AnimationManager.AddAnimation(a, "Animation");

	//m_animation.SetSpriteMap(ResourceManager::Instance()->getSurface("../data/graphics/blood.bmp"));

	m_AnimationManager.ChangeAnimation("Animation");

	GameObject::Init();

	SetX(32*16);
	SetY(20*16);


}

void PlayerTeleporter::Update()
{
	m_AnimationManager.Update(TimeManager::Instance()->getDelta(),m_X,m_Y);

}

void PlayerTeleporter::Render()
{
	m_AnimationManager.Render();

}

void PlayerTeleporter::CleanUp()
{

}