#include "Graphics/AdapterReader.h"

std::vector<AdapterData> AdapterReader::_adapters;

std::vector<AdapterData> AdapterReader::GetAdapters()
{
	if(_adapters.size() > 0) 
	{
		return _adapters;
	}

	Microsoft::WRL::ComPtr<IDXGIFactory> pFactory;

	HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)pFactory.GetAddressOf());

	if(FAILED(hr))
	{
		Logger::Log(hr, "Failed to create DXGIFactory for enumarating adapters.");
		exit(-1);
	}

	IDXGIAdapter* pAdapter;
	UINT index = 0;

	while(SUCCEEDED(pFactory->EnumAdapters(index, &pAdapter)))
	{
		_adapters.push_back(AdapterData(pAdapter));
		index++;
	}

	return _adapters;
}

AdapterData::AdapterData(IDXGIAdapter* pAdapter)
{
	_pAdapter = pAdapter;
	HRESULT hr = pAdapter->GetDesc(&_description);
	if (FAILED(hr))
	{
		Logger::Log(hr, "Failed to get IDXGIAdapter description.");
	}
}
