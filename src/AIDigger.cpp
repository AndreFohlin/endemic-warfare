#include "AIDigger.h"
#include "math.h"
#include "CollisionManager.h"
#include "Tile.h"
#include "TimeManager.h"
#include "Player.h"
#include "LevelManager.h"
#include "NPCManager.h"
#include "EnemySpawn.h"
#include "OcclusionManager.h"

#define CM CollisionManager::Instance()
#define LM LevelManager::Instance()
#define OM OcclusionManager::Instance()

AIDigger::AIDigger()
{
	m_TargetX = 0;
	m_TargetY = 0;
	m_X = 0;
	m_Y = 0;
	m_Dir.x = 0;
	m_Dir.y = 0;
	m_Speed = 50;
	m_killed = false;
	m_xindex = 0;
	m_yindex = 0;

	m_bloodTimer = 0.0f;
	m_bloodClock.Reset();
}

AIDigger::~AIDigger()
{

}

void AIDigger::Create(float startX, float startY,int id, NPCTypes npcType)
{
	m_id = id;
	setStartPosition(startX, startY);


	//EnemySpawn currentSpawn;

	//int rnd = sf::Randomizer::Random(0,3);



	//currentSpawn= LM->GetActiveLevel()->GetEnemySpawn(0);

	//int x = LM->GetActiveLevel()->GetEnemySpawn(0).GetXIndex();
	//int y = LM->GetActiveLevel()->GetEnemySpawn(0).GetYIndex();

	//setStartPosition(startX, startY);

	Animation a;
	switch(npcType)
	{
	case (DIGGER):
		//SetSprite("../data/graphics/CaveDweller.bmp");
		m_Type = DIGGER;

		//a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/CaveDweller.bmp");
		a.height = a.width = 16;
		a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/fiende1.bmp");
		a.startx = a.starty = 0;
		a.offsetx = 4;
		a.offsety = 8;
		a.nframes = 4;
		m_animation.AddAnimation(a,"walk");
		m_animation.ChangeAnimation("walk");

		break;

	case (GRUNT):
		//SetSprite("../data/graphics/grunt.bmp");
		m_Type = GRUNT;

		//Set the spritemap	
		a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/grunt.bmp");
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.offsetx = 4;
		a.offsety = 8;
		a.nframes = 4;
		m_animation.AddAnimation(a,"walk");
		m_animation.ChangeAnimation("walk");
		break;

	case (HUNTER):
		//SetSprite("../data/graphics/grunt.bmp");
		m_Type = HUNTER;

		//Set the spritemap	
		a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/hunter.bmp");
		a.height = a.width = 16;
		a.startx = a.starty = 0;
		a.offsetx = 4;
		a.offsety = 8;
		a.nframes = 4;
		m_animation.AddAnimation(a,"walk");
		m_animation.ChangeAnimation("walk");
		break;
	}
}

void AIDigger::Kill()
{
	m_killed = true;
	//SetSprite("../data/graphics/blood.bmp");

	Animation a;
	a.m_surface = ResourceManager::Instance()->getSurface("../data/graphics/blood.bmp");
	a.height = a.width = 16;
	a.startx = a.starty = 0;
	a.offsetx = 0;
	a.offsety = 0;
	a.nframes = 1;
	m_animation.AddAnimation(a,"blood");
	m_animation.ChangeAnimation("blood");

	m_bloodClock.Reset();
}


void AIDigger::setStartPosition(float x, float y)
{
	m_xindex = m_X/16;
	m_yindex = m_Y/16;

	m_TargetX = x;
	m_TargetY = y;
	m_X = x;
	m_Y = y;
	SetX(x);
	SetY(y);
}

void AIDigger::GetNewTarget()
{
	if(m_Type == DIGGER)
	{
		switch(rand()%4)
		{
		case 0:
			m_TargetX = m_X -40;
			m_Dir.x = -1;
			m_Dir.y = 0;
			break;
		case 1:
			m_TargetY = m_Y +40;
			m_Dir.x = 0;
			m_Dir.y = +1;
			break;
		case 2:
			m_TargetX = m_X +40;
			m_Dir.x = +1;
			m_Dir.y = 0;
			break;
		case 3:
			m_TargetY = m_Y -40;
			m_Dir.x = 0;
			m_Dir.y = -1;
			break;
		};
	}

	if(m_Type == GRUNT)
	{
		bool FoundDir = false;
		POINT lastdir;
		lastdir = m_Dir;

		while(!FoundDir)
		{
			switch(rand()%4)
			{
			case 0:
				m_TargetX = m_X -80;
				m_Dir.x = -1;
				m_Dir.y = 0;
				break;
			case 1:
				m_TargetY = m_Y +80;
				m_Dir.x = 0;
				m_Dir.y = +1;
				break;
			case 2:
				m_TargetX = m_X +80;
				m_Dir.x = +1;
				m_Dir.y = 0;
				break;
			case 3:
				m_TargetY = m_Y -80;
				m_Dir.x = 0;
				m_Dir.y = -1;
				break;
			};

			if(m_TargetX < 16)
			{
				m_TargetX = 16;
			}

			if(m_TargetX > 1024-16)
			{
				m_TargetX = 1024-16;
			}

			if(m_TargetY < 16)
			{
				m_TargetY = 16;
			}
			if(m_TargetY > 640-16)
			{
				m_TargetY = 640-16;
			}

			if(lastdir.x != -m_Dir.x)
			{
				FoundDir = true;
				return;
			}

			if(lastdir.y != -m_Dir.y)
			{
				FoundDir = true;
				return;
			}
		}

	}


}

void AIDigger::Render()
{
	m_animation.Render();

	//GameObject::Render();
}


void AIDigger::Update(Player* player)
{
	if(m_Type == HUNTER)
	{
		m_Dir.x = 0;
		m_Dir.y = 0;

		float DistanceToPlayerSquare;
		float vecx = m_X - player->GetX();
		float vecy = m_Y - player->GetY();

		DistanceToPlayerSquare = sqrt((vecx * vecx) + abs(vecy*vecy));

		if( abs(DistanceToPlayerSquare) < 128)
		{

			m_Dir.x = vecx;
			m_Dir.y = vecy;

			if( abs(m_Dir.x) < abs(m_Dir.y))
			{
				if(m_Dir.y < 0)
				{
					m_Dir.x = 0;
					m_Dir.y = 1;
					
				}
				else
				{
					m_Dir.x = 0;
					m_Dir.y = -1;
				}
			}
			else
			{
				if(m_Dir.x < 0)
				{
					m_Dir.x = 1;
					m_Dir.y = 0;
				}
				else
				{
					m_Dir.x = -1;
					m_Dir.y = 0;
				}
			}
			OM->ShowTile(m_X/16,m_Y/16);
			OM->ShowTile((m_X/16)+1,(m_Y/16));
			OM->ShowTile((m_X/16)-1,(m_Y/16));
			OM->ShowTile((m_X/16),(m_Y/16)+1);
			OM->ShowTile((m_X/16),(m_Y/16)-1);
		}
	}

	//Update the animation
	m_animation.Update(TimeManager::Instance()->getDelta() * 0.4f ,m_X, m_Y);
	if(m_killed)
	{
		m_bloodTimer = m_bloodClock.GetElapsedTime();

		if(m_bloodTimer >= 5.0f)
		{
			Respawn();
		}
	}
	else
	{
		float vecX = (player->GetX()+4) - GetX();
		float vecY = (player->GetY()+4) - GetY();

		float veclength = sqrt(vecX*vecX + vecY*vecY);

		veclength = abs(veclength);

		if(veclength < 7)
		{
			player->DecreaseLife(20.0f);
		}

		float xdist;
		float ydist;

		if(m_Dir.x == -1 ||m_Dir.x == 1)
		{
			xdist = abs(abs(m_TargetX) - abs(m_X));
			if(xdist < 1.0f)
			{
				GetNewTarget();
			}

		}
		if(m_Dir.y == -1 ||m_Dir.y == 1)
		{
			ydist = abs(abs(m_TargetY) - abs(m_Y));
			if(ydist < 1.0f)
			{
				GetNewTarget();
			}
		}

		if( m_Dir.x == 0 && m_Dir.y == 0 )
		{
			GetNewTarget();
		}

		Tile* CollisionTile = NULL;

		CollisionTile = CM->CheckCollision(int(m_X)+3,int(m_Y)+3, m_Dir);
		if(CollisionTile)
		{
			if(CollisionTile->GetDestroyAble())
			{
				if(CollisionTile->GetLife() <= 0)
				{
					if(m_Type == DIGGER)
					{
						CollisionTile->SetType(GRASS);
					}
					if(m_Type == GRUNT || m_Type == HUNTER)
					{
						CollisionTile->SetType(SAND);
					}

				}
				else
				{
					if(m_Type == DIGGER)
					{
						CollisionTile->DecreaseLife(TimeManager::Instance()->getDelta()*0.1);
					}
					if(m_Type == GRUNT)
					{
						CollisionTile->DecreaseLife(TimeManager::Instance()->getDelta()*0.025);
					}
					if(m_Type == HUNTER)
					{
						CollisionTile->DecreaseLife(TimeManager::Instance()->getDelta());

					}
				}
			}
			else
			{
				GetNewTarget();
			}
		}
		else
		{
			float m_walkSpeed = LM->GetActiveLevel()->GetTileManager()->GetTileFromPosition(m_X, m_Y)->GetWalkSpeed();

			float movedistx = ((m_Dir.x*5)*TimeManager::Instance()->getDelta()) * m_walkSpeed;
			float movedisty = ((m_Dir.y*5)*TimeManager::Instance()->getDelta()) * m_walkSpeed;
			SetX(m_X+(movedistx));
			SetY(m_Y+(movedisty));
		}
		if(m_Type == GRUNT)
		{
			Tile* BehindMe;

			int targetX = ((m_X+4 -((m_Dir.x*16)) )/16);
			int targetY = ((m_Y+4 -((m_Dir.y*16)) )/16);

			BehindMe = LevelManager::Instance()->GetActiveLevel()->GetTileManager()->GetTile(targetX,targetY);
			if(BehindMe)
			{
				if(BehindMe->GetType() == GRASS || BehindMe->GetType() == SAND || BehindMe->GetType() == DESTROYED)
				{
					BehindMe->SetType(WALL);
				}
			}

		}
	}
	GameObject::Update();
}

void AIDigger::Respawn()
{
	m_killed = false;
	m_animation.ChangeAnimation("walk");

	bool OK = false;

	while(!OK)
	{
		int randX = 0;
		int randY = 0;
		randX = sf::Randomizer::Random(50,950);
		randY = sf::Randomizer::Random(50,590);

		int randX2 = 0;
		int randY2 = 0;
		randX2 = sf::Randomizer::Random(50,950);
		randY2 = sf::Randomizer::Random(50,590);

		if(randX2 < 400 && randX2 > 600 && randY2 < 200 && randY2 > 450)
		{
			setStartPosition(randX,randY);
			OK = true;
		}
	}
}