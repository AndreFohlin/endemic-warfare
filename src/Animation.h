#pragma once
#include <map>
#include <sdl/sdl.h>
#include "GameObject.h"

struct Animation
{
	//Start position of frame
	float offsetx, offsety;
	float startx,starty;
	//Height and width of frame
	float height, width;
	//Number of frames
	int nframes;

	SDL_Surface*	m_surface;
};

class AnimationManager
{
public:
	AnimationManager(void);
	~AnimationManager(void);

	//void SetTime(float time);
	void SetSpriteMap(SDL_Surface* map);
	void AddAnimation(Animation a ,char* name);
	void ChangeAnimation(char* name);
	
	void Update( float dtime, float x, float y);
	void Render();

	char*	GetAnimation()	{return m_activeAnimation;}

private:

	//The animationmap
	SDL_Surface*		m_Surface;
	SDL_Rect			m_Rect;
	SDL_Rect			m_Rect2;


	//how fast will the animation be updated?

	float m_time;

	int m_frames;
	int m_activeframe;

	char* m_activeAnimation;

	std::map<char* , Animation> m_animations;
};