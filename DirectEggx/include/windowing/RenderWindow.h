#pragma once
#include "logger/Logger.h"

class RenderWindow
{
public:
	/**
	 * \fn bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height).
	 * \brief Initialises the window using win32.
	 * 
	 * \param hInstance Window instance
	 * \param title Window title
	 * \param wClass Window class
	 * \param width Width
	 * \param height Height
	 * \return 
	 */
	bool Init(HINSTANCE hInstance, std::string title, std::string wClass, int width, int height);

	/**
	 * \fn bool ProcessMessages().
	 * \brief Processess input
	 * 
	 * \return 
	 */
	bool ProcessMessages();

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
