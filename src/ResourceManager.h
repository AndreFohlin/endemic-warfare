#pragma once

#include <map>
#include <./sdl/sdl.h>

namespace sf
{
	class Sprite;
	class Image;
};


class ResourceManager
{
public:
	static ResourceManager*	Instance()
	{
		static ResourceManager instance;
		return &instance;
	}
	sf::Sprite* getSprite(std::string path);
	sf::Image& getImage(std::string path);
	SDL_Surface* getSurface(std::string path);
	
private:
	ResourceManager(){}
	~ResourceManager(){}
	std::map<std::string, sf::Sprite*> m_Sprites;
	std::map<std::string, sf::Image*> m_Images;
	std::map<std::string, SDL_Surface*> m_Surfaces;
};