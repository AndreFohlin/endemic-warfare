#include "FontManager.h"
#include "RenderWindow.h"

void FontManager::Init()
{
	if( TTF_Init() == -1)
	{
		//Couldn't init ttf
	}
	m_color.r = m_color.g = m_color.b = 255;

}

void FontManager::LoadFont(char* file, int size, char* name)
{
	TTF_Font* tmpfont;
	tmpfont = TTF_OpenFont(file, size);
	if(tmpfont == NULL)
	{
		//Problems loading font
	}
	else
	{
		m_fonts[name] = tmpfont;
	}
	
}

void FontManager::AddText(char* fontname, char* text, float x, float y)
{
	//If the chosen font exists
	if(m_fonts[fontname])
	{
		//Prepare a message and add it to the renderqueue
		Text t;
		t.text = text;
		t.font = m_fonts[fontname];
		t.x = x;
		t.y = y;
		m_messages.push_back(t);
	}
}

void FontManager::SetColor(float R, float G, float B, float A)
{
	m_color.r = R;
	m_color.g = G;
	m_color.b = B;
	m_color.unused = A;
}

void FontManager::Render()
{
	//Render all the textmessages and then empty the list
	int test = m_messages.size();
	for(int i = 0; i < test; i++)
	{
		SDL_Rect r;
		r.x = m_messages[i].x;
		r.y = m_messages[i].y;
		r.h = r.w = 100;
		m_Surface = TTF_RenderText_Blended(m_messages[i].font, m_messages[i].text,m_color);
		SDL_BlitSurface(m_Surface, NULL, RenderWindow::Instance()->GetRenderWindow(), &r);
		SDL_FreeSurface(m_Surface);
	}

	m_messages.erase(m_messages.begin(),m_messages.end());
}