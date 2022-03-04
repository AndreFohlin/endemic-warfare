#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <Assert.h>

sf::Image& ResourceManager::getImage(std::string path)
{
	if(!m_Images[path])
	{
		sf::Image* newImage;
		newImage = new sf::Image();
		m_Images[path] = newImage; 
		newImage->LoadFromFile(path.c_str());
		m_Images[path]->SetSmooth(false);
	}
	return (*m_Images[path]);
}

SDL_Surface* ResourceManager::getSurface(std::string path)
{
	if(!m_Surfaces[path])
	{
		SDL_Surface* surface;
		surface = SDL_LoadBMP(path.c_str());

		assert(path.c_str() && surface);
		if(surface)
		{
			SDL_SetColorKey( surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 255, 0, 255));
		}
		m_Surfaces[path] = surface;
	}
	return (m_Surfaces[path]);
}