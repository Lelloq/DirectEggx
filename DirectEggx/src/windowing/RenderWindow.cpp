#include "windowing/RenderWindow.h"

bool RenderWindow::Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
{
	_hInstance = hInstance;
	_width = width;
	_height = height;
	_window_title = title;
	_window_title_wide = StringConverter::StringToWide(title);
	_window_class = wClass;
	_window_class_wide = StringConverter::StringToWide(wClass);

	RegisterWindowClass();

	_handle = CreateWindowEx(0, _window_class_wide.c_str(), _window_title_wide.c_str(),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		0,0,
		_width, _height,
		NULL, NULL,
		_hInstance,
		nullptr);

	if(_handle == NULL)
	{
		Logger::Log(GetLastError(), "CreateWindowEX Faile for window: " + _window_title);
		return false;
	}

	ShowWindow(_handle, SW_SHOW);
	SetForegroundWindow(_handle);
	SetFocus(_handle);

	return true;
}

RenderWindow::~RenderWindow()
{
	if(_handle != NULL)
	{
		UnregisterClass(_window_class_wide.c_str(), _hInstance);
		DestroyWindow(_handle);
	}
}

bool RenderWindow::ProcessMessages()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	if (PeekMessage(&msg, _handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if(msg.message == WM_NULL)
	{
		if(!IsWindow(_handle))
		{
			_handle = NULL;
			UnregisterClass(_window_class_wide.c_str(), _hInstance);
			return false;
		}
	}

	return true;
}

void RenderWindow::RegisterWindowClass()
{
	WNDCLASSEX wc = {};
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = _hInstance;
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _window_class_wide.c_str();
	wc.cbSize = sizeof(WNDCLASSEX);
	RegisterClassEx(&wc);
}
