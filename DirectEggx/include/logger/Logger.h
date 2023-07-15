#pragma once
#include "StringConverter.h"
#include <Windows.h>

class Logger
{
public:
	static void Log(std::string msg);
	static void Log(HRESULT hr, std::string msg);
};
