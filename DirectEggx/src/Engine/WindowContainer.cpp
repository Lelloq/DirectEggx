#include "Engine/WindowContainer.h"

LRESULT WindowContainer::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		//Keyboard
	case WM_KEYDOWN:
	{
		unsigned kc = static_cast<unsigned char>(wParam);
		if (_keyboard.IsKeysAutoRepeat())
		{
			_keyboard.OnKeyPressed(kc);
		}
		else
		{
			const bool wasPressed = lParam & (static_cast<long long>(1) << 30);;
			if (!wasPressed)
			{
				_keyboard.OnKeyPressed(kc);
			}
		}
		return 0;
	}
	case WM_KEYUP:
	{
		unsigned kc = static_cast<unsigned char>(wParam);
		_keyboard.OnKeyReleased(kc);
		return 0;
	}
	case WM_CHAR:
	{
		unsigned ch = static_cast<unsigned char>(wParam);
		if (_keyboard.IsCharsAutoRepeat())
		{
			_keyboard.OnChar(ch);
		}
		else
		{
			const bool wasPressed = lParam & (static_cast<long long>(1) << 30);
			if (!wasPressed)
			{
				_keyboard.OnChar(ch);
			}
		}
		return 0;
	}
	//Mouse
	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnMouseMove(x, y);
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnLeftPressed(x, y);
		return 0;
	}
	case WM_MBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnMiddlePressed(x, y);
		return 0;
	}
	case WM_RBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnRightPressed(x, y);
		return 0;
	}
	case WM_LBUTTONUP:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnLeftReleased(x, y);
		return 0;
	}
	case WM_MBUTTONUP:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnRightReleased(x, y);
		return 0;
	}
	case WM_RBUTTONUP:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_mouse.OnMiddleReleased(x, y);
		return 0;
	}
	case WM_MOUSEWHEEL:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		if(GET_WHEEL_DELTA_WPARAM(wParam) > 0)
		{
			_mouse.OnWheelUp(x, y);
		}
		else if(GET_WHEEL_DELTA_WPARAM(wParam) < 0)
		{
			_mouse.OnWheelDown(x, y);
		}
		return 0;
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
