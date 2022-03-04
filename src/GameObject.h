#pragma once
#include <SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "RenderWindow.h"



class GameObject
{
public:
	GameObject(void);
	~GameObject(void);
	
	virtual void		Init();
	virtual void		CleanUp();

	virtual void		Update();
	virtual void		Render();

	virtual void		SetSprite(std::string name);
	void				SetRenderWindow();

	void				SetX(float x);
	void				SetY(float y);
	float				GetX(){return m_X;}
	float				GetY(){return m_Y;}

protected:
	//sf::Sprite			m_Sprite;
	SDL_Surface*		m_Surface;
	float m_X, m_Y;

private:
	

};
