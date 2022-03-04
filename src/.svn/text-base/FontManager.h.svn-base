#pragma once

#include <./sdl/sdl_ttf.h>
#include <./sdl/sdl.h>
#include <map>
#include <vector>

struct Text
{
	char* text;
	TTF_Font* font;
	float x, y;
};

class FontManager
{
public:	
	
	static FontManager*	Instance()
	{
		static FontManager instance;
		return &instance;
	}
	
	void Init();
	void AddText(char* fontname, char* text, float x, float y);
	void SetColor(float R, float G, float B, float A);
	void LoadFont(char* file, int size, char* name);
	void Render();
private:

	FontManager(void){}
	~FontManager(void){}

	//Fontlist
	std::map<char*, TTF_Font*> m_fonts;
	std::vector<Text> m_messages;

	//The fontsurface
	SDL_Surface* m_Surface;

	//Color!!
	SDL_Color m_color;

};