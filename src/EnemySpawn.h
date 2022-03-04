#pragma once
#include "GameObject.h"
#include "Animation.h"


class EnemySpawn : public GameObject
{
public:
	EnemySpawn ();
	~EnemySpawn ();
	void Init(float xPos, float yPos);
	void Update();
	void Render();
	void CleanUp();
	
 	int GetXIndex()	{return m_xIndex;}
	int GetYIndex()	{return m_yIndex;}

//	float GetXPos()	{return m_Sprite.GetLeft();}
//	float GetYPos()	{return m_Sprite.GetTop();}

private:
	AnimationManager m_AnimationManager;

	float m_xpos, m_ypos;
	int m_xIndex, m_yIndex;
};


