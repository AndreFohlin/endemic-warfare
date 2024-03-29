#include "LevelObject.h"
#include "OcclusionManager.h"
#include "NPCManager.h"
#include "math.h"

LevelObject::LevelObject(void)
{
	
}

LevelObject::~LevelObject(void)
{
}

void LevelObject::Create(std::string xmlPath)
{
	TiXmlDocument	levelXML;

	if(levelXML.LoadFile( xmlPath.c_str() ))
	{
		TiXmlNode		*RootNode		= NULL;
		TiXmlElement	*DataElement	= NULL;

		RootNode = levelXML.RootElement();

		// -Create Map- //
		DataElement = RootNode->FirstChildElement("Level");

		// -Picture Path
		std::string picPath = DataElement->Attribute("map");

		// -Tile Width & Height
		int tileW = atoi(DataElement->Attribute("tileX"));
		int tileH = atoi(DataElement->Attribute("tileY"));

		this->CreateMap(picPath, tileW, tileH);

		// -Create Player- //
		DataElement = DataElement->NextSiblingElement();

		picPath = DataElement->Attribute("image");

		int startX = atoi(DataElement->Attribute("startX"));
		int startY = atoi(DataElement->Attribute("startY"));

		this->CreatePlayer(picPath, startX, startY);

		// -Create Items- //
		DataElement = DataElement->NextSiblingElement();
		std::string xmlPath = DataElement->Attribute("itemsXML");

		this->CreateItems( xmlPath.c_str() );

		// -Create Enemies- //
		DataElement = DataElement->NextSiblingElement();
		xmlPath = DataElement->Attribute("npcXML");

		this->CreateSpawnPoints();
		this->CreateEnemies( xmlPath.c_str() );
	}
	else
	{

	}


	//OcclusionManager::Instance()->Init("../data/graphics/black.bmp");
}

void LevelObject::Render()
{
	// -Render Level
	m_TileManager.Render();

	m_PlayerTeleporter.Render();

	m_enemySpawn[0].Render();
	m_enemySpawn[1].Render();
	m_enemySpawn[2].Render();
	m_enemySpawn[3].Render();
	// -Render Items
	int itemSize = m_Items.size();
	for(int i = 0; i < itemSize; i++)
	{
		m_Items[i].Render();
	}

	NPCManager::Instance()->Render();
	
	// -Render Player
	m_Player.Render();


	// -Render Enemeies
	//OcclusionManager::Instance()->Render();
}

void LevelObject::Update()
{

	m_PlayerTeleporter.Update();
	m_enemySpawn[0].Update();
	m_enemySpawn[1].Update();
	m_enemySpawn[2].Update();
	m_enemySpawn[3].Update();
	// -Update Tiles
	m_TileManager.Update();

	// -Update Player
	m_Player.Update();

	// -Update Items
	for(unsigned int i = 0; i < m_Items.size(); i++)
	{
		m_Items[i].Update(&m_Player);
	}

	NPCManager::Instance()->Update(&m_Player);

	// -Update Enemeies
}

bool LevelObject::CreateMap(std::string pic, int tileX, int tileY)
{
	m_TileManager.InitTiles(&ResourceManager::Instance()->getImage(pic.c_str()), tileX, tileY);

	return 1;
}

bool LevelObject::CreatePlayer(std::string pic, int startX, int startY)
{
	// -Create Player
	m_Player.SetSprite( pic.c_str() );
	m_Player.Init();

	m_Player.SetY( m_TileManager.GetTile(startX, startY)->GetY() );
	m_Player.SetX( m_TileManager.GetTile(startX, startY)->GetX() );
	m_TileManager.GetTile(startX, startY)->SetType(SAND);

	return 1;
}

bool LevelObject::CreateItems(std::string xml)
{
	TiXmlDocument	levelXML;

	if(levelXML.LoadFile( xml.c_str() ))
	{
		TiXmlNode		*RootNode		= NULL;
		TiXmlElement	*DataElement	= NULL;

		RootNode = levelXML.RootElement();

		
		// -Create Items- //
		DataElement = RootNode->FirstChildElement("Item");
		while(DataElement)
		{
			std::string path = DataElement->Attribute("path");
			int startX = atoi(DataElement->Attribute("tilex"));
			int startY = atoi(DataElement->Attribute("tiley"));
			int type = atoi(DataElement->Attribute("type"));
			Item m;
			Tile* t;
			t = m_TileManager.GetTile(startX,startY);
			m_TileManager.GetTile(startX, startY)->SetType(SAND);
			m.SetSprite(path);
			m.Init(type);
			m.SetX(t->GetX());
			m.SetY(t->GetY());
			int tempx;
			int tempy;
			tempx = (rand()%1024-64)+32;
			tempy = (rand()%512-64)+32;
			tempx = ((tempx/16)*16);
			tempy = ((tempy/16)*16);


			m.SetX(tempx);
			m.SetY(tempy);
			m_Items.push_back(m);

			DataElement = DataElement->NextSiblingElement();
		}

		return 1;
	}
	return 0;
}	

bool LevelObject::CreateEnemies(std::string xml)
{
	TiXmlDocument	npcXML;

	if(npcXML.LoadFile( xml.c_str() ))
	{
		TiXmlNode		*RootNode		= NULL;
		TiXmlElement	*DataElement	= NULL;

		RootNode = npcXML.RootElement();

		// -Create Items- //
		DataElement = RootNode->FirstChildElement("NPC");
		while(DataElement)
		{
			std::string typeSTR = DataElement->Attribute("type");

			int type;

			if(typeSTR == "DIGGER")		{ type = 0; }
			if(typeSTR == "WOMAN")		{ type = 1; }
			if(typeSTR == "HUNTER")		{ type = 2; }
			if(typeSTR == "DRONE")		{ type = 3; }
			if(typeSTR == "GRUNT")		{ type = 4; }

			NPCManager::Instance()->Add(rand()%(1024-64)+32,rand()%(640-64)+32, (NPCTypes)type);	
			DataElement = DataElement->NextSiblingElement();
		}
		
		return 1;
	}
	
	return 0;
}

bool LevelObject::CheckNPC(float xPos, float yPos)
{
	int indexX = m_TileManager.GetTileFromPosition(xPos, yPos)->GetXIndex();
	int indexY = m_TileManager.GetTileFromPosition(xPos, yPos)->GetYIndex();

	int npcSize = NPCManager::Instance()->m_diggerVector.size();
	for(int i = 0; i < npcSize; i++)
	{
		float npcX = NPCManager::Instance()->m_diggerVector[i].GetX();
		float npcY = NPCManager::Instance()->m_diggerVector[i].GetY();

		float vecX = (npcX+4) - xPos;
		float vecY = (npcY+4) - yPos;

		float veclength = sqrt(vecX*vecX + vecY*vecY);
		
		veclength = abs(veclength);

		if(veclength < 10)
		{
			NPCManager::Instance()->m_diggerVector[i].Kill();
			return 1;
		}

		//if(npcX == indexX && npcY  == indexY)
		//{
		//	NPCManager::Instance()->m_diggerVector[i].Kill();
		//	return 1;
		//}
	}
	return 0;
}

EnemySpawn LevelObject::GetEnemySpawn(int index)
{
	return m_enemySpawn[index];
}

void LevelObject::CreateSpawnPoints()
{
	m_PlayerTeleporter.Init();

	float randomX; 
	float randomY; 

	//m_enemySpawn = new EnemySpawn[4];

	randomX = sf::Randomizer::Random(32,512-100);
	randomY = sf::Randomizer::Random(32,310-32);
	m_enemySpawn[0].Init(randomX,randomY);

	randomX = sf::Randomizer::Random(512+100,1024-32);
	randomY = sf::Randomizer::Random(32,310-32);
	m_enemySpawn[1].Init(randomX,randomY);

	randomX = sf::Randomizer::Random(32,512-100);
	randomY = sf::Randomizer::Random(310+32,640-32);
	m_enemySpawn[2].Init(randomX,randomY);

	randomX = sf::Randomizer::Random(512+100,1024-32);
	randomY = sf::Randomizer::Random(310+32,640-32);
	m_enemySpawn[3].Init(randomX,randomY);
}