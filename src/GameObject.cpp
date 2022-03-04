#include "GameObject.h"
#define RW RenderWindow::Instance()->GetRenderWindow()
#define RM ResourceManager::Instance()


GameObject::GameObject(void)
{
	//m_Sprite = NULL;
	m_X = m_Y = 0;
}

GameObject::~GameObject(void)
{
}
	
void GameObject::Init()
{
}

void GameObject::CleanUp()
{
}

void GameObject::Update()
{
	//m_Sprite.SetTop(m_Y);
	//m_Sprite.SetLeft(m_X);
}

void GameObject::Render()
{
	SDL_Rect bob;
	bob.x = int(m_X);
	bob.y = int(m_Y);
	SDL_BlitSurface(m_Surface, NULL, RenderWindow::Instance()->GetRenderWindow(), &bob);
}

void GameObject::SetSprite(std::string name)
{
	m_Surface = ResourceManager::Instance()->getSurface(name.c_str());
	/*
	m_Surface = SDL_LoadBMP(name.c_str());
	if(m_Surface)
	{
		SDL_SetColorKey( m_Surface, SDL_SRCCOLORKEY, SDL_MapRGB(m_Surface->format, 255, 0, 255));
	}
	*/

	//m_Sprite.SetImage(ResourceManager::Instance()->getImage(name.c_str()));
}

void GameObject::SetX(float x)
{
	m_X = x;
	//m_Sprite.SetLeft(x);
}
void GameObject::SetY(float y)
{
	m_Y = y;
	//m_Sprite.SetTop(y);
}