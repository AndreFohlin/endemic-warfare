#include "CollisionManager.h"
#include "LevelManager.h"

CollisionManager* CollisionManager::Instance()
{
	static CollisionManager instance;

	return &instance;
}

Tile* CollisionManager::CheckCollision(int xPos, int yPos, POINT direction)
{
	Tile* startTile = GetTile(xPos, yPos);

	TileManager* m_TileManager = LevelManager::Instance()->GetActiveLevel()->GetTileManager();

	sf::IntRect collBox1 = sf::IntRect(xPos - 5, yPos - 5, xPos + 5, yPos + 5);

	// -Check Collision Y+
	if(direction.y > 0)	
	{
		sf::IntRect checkRect1 = m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() + 1)->GetRect();

		if(collBox1.Intersects(checkRect1))
		{	
			if(!m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() + 1)->GetWalkable())
			{
				return m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() + 1);
			}
		}
	}

	// -Check Collision Y-
	if(direction.y < 0)	
	{
		sf::IntRect checkRect1 = m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() - 1)->GetRect();

		if(collBox1.Intersects(checkRect1))
		{	
			if(!m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() - 1)->GetWalkable())
			{
				return m_TileManager->GetTile(startTile->GetXIndex(), startTile->GetYIndex() - 1);
			}
		}
	}

	// -Check Collision X+
	if(direction.x > 0)	
	{
		sf::IntRect checkRect1 = m_TileManager->GetTile(startTile->GetXIndex() + 1, startTile->GetYIndex())->GetRect();

		if(collBox1.Intersects(checkRect1))
		{	
			if(!m_TileManager->GetTile(startTile->GetXIndex() + 1, startTile->GetYIndex())->GetWalkable())	
			{
				return m_TileManager->GetTile(startTile->GetXIndex() + 1, startTile->GetYIndex());
			}
		}
	}

	// -Check Collision Y-
	if(direction.x < 0)	
	{
		sf::IntRect checkRect1 = m_TileManager->GetTile(startTile->GetXIndex() - 1, startTile->GetYIndex())->GetRect();

		if(collBox1.Intersects(checkRect1))
		{	
			if(!m_TileManager->GetTile(startTile->GetXIndex() - 1, startTile->GetYIndex())->GetWalkable())
			{
				return m_TileManager->GetTile(startTile->GetXIndex() - 1, startTile->GetYIndex());
			}
		}
	}
	return 0;
}

Tile* CollisionManager::GetTile(float xPos, float yPos)
{
	if(xPos < 1024 && xPos >= 0 && yPos < 640 && yPos >= 0)
	{
		TileManager* m_TileManager = LevelManager::Instance()->GetActiveLevel()->GetTileManager();
		return m_TileManager->GetTileFromPosition(xPos, yPos);
	}
	return NULL;
}
