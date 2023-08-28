#pragma once
#include "logger/Logger.h"

class WindowContainer;

//Win32 window stuff, I think this can be detached later on and be used for something else
class RenderWindow
{
public:
	/**
	 * \fn bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height).
	 * \brief Initialises the window using win32.
	 *
	 * \param wc pointer to the window container
	 * \param hInstance Window instance
	 * \param title Window title
	 * \param wClass Window class
	 * \param width Width
	 * \param height Height
	 * \return
	 */
	bool Init(WindowContainer* wc, HINSTANCE hInstance, std::string title, std::string wClass, int width, int height);

	/**
	 * \fn bool ProcessMessages().
	 * \brief Processess input
	 *
	 * \return
	 */
	bool ProcessMessages();

	inline HWND GetHWND() const { return _handle; }

	/**
	 * \brief Window destructor.
	 *
	 */
	~RenderWindow();
private:
	/**
	 * \fn void RegisterWindowClass().
	 * \brief Creates a window class for the window instance.
	 */
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
