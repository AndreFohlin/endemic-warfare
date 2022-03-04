#include "Item.h"
#include "Player.h"
#include <cmath>

#include "SoundManager.h"
#include "TimeManager.h"
#include "ScoreManager.h"
#include "LevelManager.h"


Item::Item()
{
	type = 666;
	m_activated = false;
}

Item::~Item()
{
}

void Item::Init(int t)
{
	type = t;
	bool b = true;
	Animation a;
	a.m_surface = m_Surface;


	switch(type)
	{
	case 0:
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.nframes = 1;
		a.offsetx = a.offsety = 0;
		m_animation.AddAnimation(a, "bling");
		break;
	case 1:
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.nframes = 2;
		a.offsetx = a.offsety = 0;
		m_animation.AddAnimation(a, "bling");
		break;
	case 2:
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.nframes = 1;
		a.offsetx = a.offsety = 0;
		m_animation.AddAnimation(a, "bling");
		break;
	case 3:
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.nframes = 4;
		a.offsetx = a.offsety = 0;
		m_animation.AddAnimation(a, "bling");
		break;
	}
	m_animation.ChangeAnimation("bling");

}

void Item::Update(Player* player)
{
	float delta = TimeManager::Instance()->getDelta();

	//Update animation
	m_animation.Update(delta*0.4f, m_X, m_Y);

	float vecX = (player->GetX()+4) - GetX()-4;
	float vecY = (player->GetY()+4) - GetY()-4;

	float veclength = sqrt(vecX*vecX + vecY*vecY);

	veclength = abs(veclength);

	//Add effect depending on type on item
	if(!m_activated)
	if(veclength < 10.0f)
	{
		//m_activated = true;
		switch(type)
		{
			//MEAD
		case 0:
			player->SetSpeed(player->GetSpeed() + 10);
			ScoreManager::Instance()->AddScore(3000,MEAD);
			break;
			//Bomb
		case 1:
			player->AddBombs(10);
			ScoreManager::Instance()->AddScore(1000,BOMB);
			break;
			//Girl
		case 2:
			ScoreManager::Instance()->AddScore(4000,WOMEN);
			SoundManager::Instance()->PlaySound("GetGirl",255);
			break;
			//Gold
		case 3:
			ScoreManager::Instance()->AddScore(2000,GOLD);
			break;
		}
		SetX(16* ( (rand()%56)+4));
		SetY(16* ( (rand()%24)+4));



		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile(m_X/16,m_Y/16)->SetType(SAND);

		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)+1,(m_Y/16))->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)-1,(m_Y/16))->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16),(m_Y/16)+1)->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16),(m_Y/16)-1)->SetType(WALL);

		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)+1,(m_Y/16)+1)->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)-1,(m_Y/16)-1)->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)-1,(m_Y/16)+1)->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X/16)+1,(m_Y/16)-1)->SetType(WALL);


		/*
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X-16/16),(m_Y-16/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X+16/16),(m_Y+16/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X-0/16),(m_Y-16/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X-16/16),(m_Y-0/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X-0/16),(m_Y+16/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X+16/16),(m_Y-0/16) )->SetType(WALL);
		LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile((m_X+16/16),(m_Y-16/16) )->SetType(WALL);
		*/
		
	}
	GameObject::Update();
}

void Item::CleanUp()
{
}

void Item::Render()
{
	if(!m_activated)
	{
		m_animation.Render();
		//GameObject::Render();
	}
}