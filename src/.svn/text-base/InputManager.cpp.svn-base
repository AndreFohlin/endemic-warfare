#include "Inputmanager.h"



InputManager::InputManager()
{
	for(int i = 0; i < 256; i++)
	{
		m_Key[i] = false;
	}

}

void InputManager::Update()
{
	SDL_Event event;

	while(SDL_PollEvent(&event)) 
	{
		switch(event.key.state)
		{
			case SDL_PRESSED:
				int keycode;
				keycode = event.key.keysym.scancode;
				if(keycode)
				{
					m_Key[event.key.keysym.scancode] = true;
				}
				break;
			case SDL_RELEASED:
				m_Key[event.key.keysym.scancode] = false;
				break;
			case SDL_QUIT:

				break;
		}
	}
}

bool InputManager::getKey(char key)
{

	return m_Key[key];
}