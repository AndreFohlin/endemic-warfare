#pragma once

#include <./sdl/sdl.h>

class InputManager
{
public:

	static InputManager* Instance()
	{
		static InputManager instance;
		return &instance;
	}
	bool getKey(char key);
	void Update();

private:
	InputManager();

	InputManager(const InputManager&);
	InputManager& operator=(const InputManager&);
	
	bool m_Key[256];
};