#include "logger/Logger.h"
#include <comdef.h>

void Logger::Log(std::string msg)
{
	std::string err_msg = "Error:" + msg;
	MessageBoxA(NULL, err_msg.c_str(), "Error", MB_ICONERROR);
}

void Logger::Log(HRESULT hr, std::string msg)
{
	_com_error error(hr);
	std::wstring err_msg = L"Error:" + StringConverter::StringToWide(msg) + L"\n" + error.ErrorMessage();
	MessageBoxW(NULL, err_msg.c_str(), L"Error", MB_ICONERROR);
}

void Logger::Log(HRESULT hr, std::wstring msg)
{
	_com_error error(hr);
	std::wstring err_msg = L"Error:" + msg + L"\n" + error.ErrorMessage();
	MessageBoxW(NULL, err_msg.c_str(), L"Error", MB_ICONERROR);
}
