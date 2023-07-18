#pragma once
#include "windowing/RenderWindow.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

class WindowContainer
{
public:
	WindowContainer();
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	RenderWindow _render_window;
	Keyboard _keyboard;
	Mouse _mouse;
};
