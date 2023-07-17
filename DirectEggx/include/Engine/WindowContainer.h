#pragma once
#include "windowing/RenderWindow.h"

class WindowContainer
{
public:
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	RenderWindow _render_window;
};
