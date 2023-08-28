#include "Engine/WindowContainer.h"

bool RenderWindow::Init(WindowContainer* wc, HINSTANCE hInstance, std::string title, std::string wClass, int width, int height)
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
		0, 0,
		_width, _height,
		NULL, NULL,
		_hInstance,
		wc);

	if (_handle == NULL)
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
	if (_handle != NULL)
	{
		UnregisterClass(_window_class_wide.c_str(), _hInstance);
		DestroyWindow(_handle);
	}
}

bool RenderWindow::ProcessMessages()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (PeekMessage(&msg, _handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (msg.message == WM_NULL)
	{
		if (!IsWindow(_handle))
		{
			_handle = NULL;
			UnregisterClass(_window_class_wide.c_str(), _hInstance);
			return false;
		}
	}

	return true;
}

//Redirects input messages to the active window
LRESULT HandleMsgRedirect(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
	default:
		WindowContainer* const pWindow = reinterpret_cast<WindowContainer*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		return pWindow->WindowProc(hwnd, uMsg, wParam, lParam);
	}
}

//Initialization of the input messages when a window is created
LRESULT CALLBACK HandleMsgSetup(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_NCCREATE:
	{
		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
		WindowContainer* pWindow = reinterpret_cast<WindowContainer*>(pCreate->lpCreateParams);
		if (pWindow == nullptr)
		{
			Logger::Log("CRITICAL ERROR: Pointer to window container is null during WM_NCCREATE");
			exit(-1);
		}
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
		SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(HandleMsgRedirect));
		return pWindow->WindowProc(hwnd, uMsg, wParam, lParam);
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

void RenderWindow::RegisterWindowClass()
{
	WNDCLASSEX wc = {};
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = HandleMsgSetup;
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