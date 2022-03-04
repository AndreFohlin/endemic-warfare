#include <Windows.h>
#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	// -Engine Pointer 
	Engine* cEngine;

	// -New the Engine Pointer
	cEngine = new Engine();

	cEngine->Init(1024, 768, "Viking");

	// -Main Loop
	while(cEngine->IsRunning())
	{
		cEngine->Update();
		cEngine->Render();
	}

	delete cEngine;
	return EXIT_SUCCESS;
}
