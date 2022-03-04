#include "HUD.h"	
#include "Player.h"
#include "ScoreManager.h"

#define FM FontManager::Instance()

HUD::HUD(void)
{
	m_timeIsUp = false;
}

HUD::~HUD(void)
{
}

void HUD::Init(float x, float y)
{
	//TimerSettings
	m_Clock.Reset();
	//m_minutes = 0;
	//m_seconds = 10;

	//Text.SetFont("../data/font/arial.ttf");
	FM->Init();
	FM->LoadFont("../data/font/arial.ttf" ,20, "arial");
	FM->LoadFont("../data/font/arial.ttf" ,20, "goth1");
	FM->LoadFont("../data/font/arial.ttf" ,30, "goth2");
	
	//Init graphics
	m_back.Init();
	m_back.SetSprite("../data/graphics/HUD.bmp");
	m_back.SetY(y);
	m_back.SetX(x);
	

	//All vikingmodes
	m_VikingPic1.Init();
	m_VikingPic1.SetSprite("../data/graphics/viking_nykter.bmp");
	m_VikingPic1.SetX(x + 485);
	m_VikingPic1.SetY(y + 40);

	m_VikingPic2.Init();
	m_VikingPic2.SetSprite("../data/graphics/viking_lullig.bmp");
	m_VikingPic2.SetX(x + 485);
	m_VikingPic2.SetY(y + 40);

	m_VikingPic3.Init();
	m_VikingPic3.SetSprite("../data/graphics/viking_full.bmp");
	m_VikingPic3.SetX(x + 485);
	m_VikingPic3.SetY(y + 40);

	m_VikingPic4.Init();
	m_VikingPic4.SetSprite("../data/graphics/viking_appackad.bmp");
	m_VikingPic4.SetX(x + 485);
	m_VikingPic4.SetY(y + 40);


	m_BombPic.Init();
	m_BombPic.SetSprite("../data/graphics/bombshow.bmp");
	m_BombPic.SetX(x + 220);
	m_BombPic.SetY(y + 20);

	m_GirlPic.Init();
	m_GirlPic.SetSprite("../data/graphics/girlshow.bmp");
	m_GirlPic.SetX(x + 420);
	m_GirlPic.SetY(y + 20);

	
}
void HUD::SetTime(int minutes, int seconds)
{
	m_minutes = minutes;
	m_seconds = seconds;
	m_timeIsUp = false;
}


void HUD::Render(Player* player)
{
	m_back.Render();
	switch(ScoreManager::Instance()->getMead())
	{
	case 0:
		m_VikingPic1.Render();
		break;
	case 1:
		m_VikingPic2.Render();
		break;
	case 2:
		m_VikingPic3.Render();
		break;
	case 3:
		m_VikingPic4.Render();
		break;
	}
	
	//Convert the timevariables to chars
	char buf1[10];
	char buf2[10];
	//Bombs
	char buf3[10];
	//Women
	char buf5[10];
	//Mead
	char buf6[10];
	//Gold
	char buf7[10];


	//Score
	char buf4[10];

	//The timetext
	//FM->AddText("goth1", "Time Left",800,660);
	itoa(m_minutes,buf1,10);
	FM->AddText("goth2", buf1,810,665);
	FM->AddText("goth2", ":",825,665);
	itoa(m_seconds,buf2,10);
	FM->AddText("goth2", buf2,835,665);
	

	//The Scoretext
	//FM->AddText("goth1", "Score:",800,690);
	itoa(ScoreManager::Instance()->GetScore(),buf4,10);
	FM->AddText("goth2", buf4,735,712);

	//The itemtext
	//FM->AddText("arial", "Bombs Left:",800,690);
	int bombs = player->GetNrOfBombs();
	itoa(bombs, buf3,10);
	FM->AddText("goth2", buf3,58,717);


	//Mead
	itoa(ScoreManager::Instance()->getMead(),buf6,10);
	FM->AddText("goth2",buf6,168,717);

	//Women
	itoa(ScoreManager::Instance()->m_Women,buf5,10);
	FM->AddText("goth2",buf5,378,717);

	//Gold
	itoa(ScoreManager::Instance()->m_Gold,buf7,10);
	FM->AddText("goth2",buf7,270,717);

	//FM->SetColor(255,0,0,255);
	FM->Render();
}

void HUD::Update()
{
	
	//When updating the time will decrease
	float delta = m_Clock.GetElapsedTime();
	
	m_seconds -= delta;
	
	//If seconds is under 0. a minute has passed
	if(m_seconds < 0.0f)
	{
		//if no minutes left. times up!
		if(m_minutes <= 0)
		{
			m_timeIsUp = true;
		}
		else
		{
			m_minutes--;
			m_seconds = 60;
		}
	}

	//Reset the timer to be able to get a new delta time next update
	m_Clock.Reset();

	int bombs = Player::Instance()->GetNrOfBombs();
}