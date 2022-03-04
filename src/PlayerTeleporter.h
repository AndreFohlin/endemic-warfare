#pragma once
#include "GameObject.h"
#include "Animation.h"


class PlayerTeleporter : public GameObject
{
public:
	PlayerTeleporter ();
	~PlayerTeleporter ();
	void Init();
	void Update();
	void Render();
	void CleanUp();
private:
	AnimationManager m_AnimationManager;


};


