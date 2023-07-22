#include "Engine/Engine.h"

bool Engine::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	if(!_render_window.Init(this, hInstance, title, wClass, width, height))
	{
		return false;
	}
	if(!_gfx.Init(_render_window.GetHWND(), width, height))
	{
		return false;
	}
	return true;
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

void Engine::Render()
{
	_gfx.RenderFrame();
}
