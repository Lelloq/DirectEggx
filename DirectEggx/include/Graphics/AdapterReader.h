#pragma once
#include "logger/Logger.h"
#include <d3d11.h>
#include <wrl/client.h>
#include <vector>

class AdapterData 
{
public:
	AdapterData(IDXGIAdapter* pAdapter);
	IDXGIAdapter* _pAdapter = nullptr;
	DXGI_ADAPTER_DESC _description;
};


class AdapterReader
{
public:
	static std::vector<AdapterData> GetAdapters();
private:
	static std::vector<AdapterData> _adapters;
};
