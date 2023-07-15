#pragma once
#include "logger/Logger.h"

class RenderWindow
{
public:
	bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height);
	bool ProcessMessages();
	~RenderWindow();
private:
	void RegisterWindowClass();
	HWND _handle = NULL;
	HINSTANCE _hInstance = NULL;
	std::string _window_title = "";
	std::wstring _window_title_wide = L"";
	std::string _window_class = "";
	std::wstring _window_class_wide = L"";
	int _width = 0;
	int _height = 0;
};
