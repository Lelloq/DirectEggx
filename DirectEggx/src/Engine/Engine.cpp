#include "Engine/Engine.h"

bool Engine::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	return _render_window.Init(this, hInstance, title, wClass, width, height);
}

bool Engine::ProcessMessages()
{
	return _render_window.ProcessMessages();
}

void Engine::Update()
{
	while(!_keyboard.IsCharBufferEmpty())
	{
		unsigned char ch = _keyboard.ReadChar();
	}

	while(!_keyboard.IsKeyBufferEmpty())
	{
		KeyboardEvent kbe = _keyboard.ReadKey();
		unsigned char kc = kbe.GetKeycode();
	}

	while(!_mouse.IsEventBufferEmpty())
	{
		MouseEvent me = _mouse.ReadEvent();
	}
}
