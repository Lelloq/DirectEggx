#include "windowing/RenderWindow.h"

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR     lpCmdLine,
	_In_ int       nCmdShow) 
{
	RenderWindow window;
	window.Init(hInstance, "Test", "Test Class", 1280, 720);
	while(window.ProcessMessages() == true)
	{
	}
	return 0;
};
