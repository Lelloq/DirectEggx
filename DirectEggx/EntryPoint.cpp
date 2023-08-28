#include "Engine/Engine.h"

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	Engine engine;
	if (engine.Init(hInstance, "Test", "Test Class", 1280, 720))
	{
		while (engine.ProcessMessages() == true)
		{
			engine.Update();
			engine.Render();
		}
	}
	return 0;
};