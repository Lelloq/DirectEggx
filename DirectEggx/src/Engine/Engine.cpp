#include "Engine/Engine.h"

bool Engine::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	return _render_window.Init(this, hInstance, title, wClass, width, height);
}

bool Engine::ProcessMessages()
{
	return _render_window.ProcessMessages();
}
