#include "LevelManager.h"

LevelManager* LevelManager::Instance()
{
	static LevelManager instance;

	return &instance;
}

void LevelManager::AddLevel(std::string picPath, std::string LevelName)
{
	LevelObject levelObject;

	levelObject.Create( picPath.c_str() );

	LevelObjects[ LevelName.c_str() ] = levelObject;
}

void LevelManager::Render()
{
	m_ActiveLevel.Render();
}

void LevelManager::Update()
{
	m_ActiveLevel.Update();
}

void LevelManager::SetActiveLevel(std::string LevelName)
{
	m_ActiveLevel = LevelObjects[LevelName];
}


bool LevelManager::GetEnemyCollision(float xPos, float yPos)
{	
	if(GetActiveLevel()->CheckNPC(xPos, yPos))
	{
		return 1;
	}
	return 0;
}