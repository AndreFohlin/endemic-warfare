#include "OcclusionManager.h"
#include <./SDL/SDL.h>
#include "RenderWindow.h"
#include "ResourceManager.h"

OcclusionManager::OcclusionManager()
{
	for(int y =0; y <40; y++)
	{
		for(int x =0; x <64; x++)
		{
			m_Visable[x][y] = false;
		}
	}


}

void OcclusionManager::ShowTile(int x, int y)
{
	if(x < 64 && x >= 0 && y < 40 && y >= 0)
	{
		m_Visable[x][y] = true;


	}



}

void OcclusionManager::Show(int x, int y)
{
	int XID;
	int YID;
	XID = (x+4)/16;
	YID = (y+4)/16;


	int TargetX;
	int TargetY;

	TargetX = XID ;
	TargetY = YID ;
	ShowTile(TargetX,TargetY);

	TargetX = XID +1;
	TargetY = YID +1;
	ShowTile(TargetX,TargetY);

	TargetX = XID +1;
	TargetY = YID +0;
	ShowTile(TargetX,TargetY);

	TargetX = XID +2;
	TargetY = YID +0;
	ShowTile(TargetX,TargetY);

	TargetX = XID +0;
	TargetY = YID +1;
	ShowTile(TargetX,TargetY);

	TargetX = XID +0;
	TargetY = YID +2;
	ShowTile(TargetX,TargetY);

	TargetX = XID -1;
	TargetY = YID -1;
	ShowTile(TargetX,TargetY);

	TargetX = XID -1;
	TargetY = YID - 0;
	ShowTile(TargetX,TargetY);

	TargetX = XID -2;
	TargetY = YID -0;
	ShowTile(TargetX,TargetY);

	TargetX = XID -0;
	TargetY = YID -1;
	ShowTile(TargetX,TargetY);

	TargetX = XID -0;
	TargetY = YID -2;
	ShowTile(TargetX,TargetY);


	TargetX = XID +1;
	TargetY = YID -1;
	ShowTile(TargetX,TargetY);

	TargetX = XID -1;
	TargetY = YID +1;
	ShowTile(TargetX,TargetY);

}

void OcclusionManager::Init(char* path)
{
	m_Surface = ResourceManager::Instance()->getSurface("../data/graphics/black.bmp");
	//m_Surface = SDL_LoadBMP(path);
}

bool OcclusionManager::isHidden(int x, int y)
{
	if(x >=0 && x < 64)
	{
		if(y >=0 && y < 40)
		{
			return !(m_Visable[x][y]);
		}
	}
	return true;



}

void OcclusionManager::Render()
{
	for(int y =0; y <40; y++)
	{
		for(int x =0; x <64; x++)
		{
			int tiletype = 0;

			int neighbourx = x;
			int neighboury = y;

			if(m_Visable[x][y])
			{
				
			}
			else
			{
				SDL_Rect dest;
				dest.x = x*16;
				dest.y = y*16;
				dest.w =0;
				dest.h =0;

				SDL_BlitSurface(m_Surface,0,RenderWindow::Instance()->GetRenderWindow(),&dest);

			}
		}
	}
}
