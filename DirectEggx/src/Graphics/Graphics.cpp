#include "Graphics/Graphics.h"

bool Graphics::Init(HWND hwnd, int width, int height)
{
	if (!InitDX(hwnd, width, height))
		return false;

	if (!InitShaders())
		return false;

	return true;
}

void Graphics::RenderFrame()
{
	float bgColor[] = { 0.f,0.f,0.f,1.f };
	_deviceContext->ClearRenderTargetView(_renderTargetView.Get(), bgColor);
	_swapchain->Present(1, NULL);
}

bool Graphics::InitDX(HWND hwnd, int width, int height)
{
	std::vector<AdapterData> adapters = AdapterReader::GetAdapters();

	if (adapters.size() < 1)
	{
		Logger::Log("No DXGI adapters found");
		return false;
	}

	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	scd.BufferDesc.Width = width;
	scd.BufferDesc.Height = height;
	scd.BufferDesc.RefreshRate.Numerator = 144;
	scd.BufferDesc.RefreshRate.Denominator = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	scd.SampleDesc.Count = 1;
	scd.SampleDesc.Quality = 0;

	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.BufferCount = 1;
	scd.OutputWindow = hwnd;
	scd.Windowed = true;
	scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	HRESULT hr;

	hr = D3D11CreateDeviceAndSwapChain(
		adapters[0]._pAdapter,//Only passing in the first one for now
		D3D_DRIVER_TYPE_UNKNOWN,
		NULL,
		NULL,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&scd,
		_swapchain.GetAddressOf(),
		_device.GetAddressOf(),
		NULL,
		_deviceContext.GetAddressOf());

	if (FAILED(hr))
	{
		Logger::Log("Failed to create D3D11 device and swap chain");
		return false;
	}

	Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer;
	hr = _swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(backBuffer.GetAddressOf()));
	if (FAILED(hr))
	{
		Logger::Log(hr, "GetBuffer failed.");
		return false;
	}

	hr = _device->CreateRenderTargetView(backBuffer.Get(), NULL, _renderTargetView.GetAddressOf());
	if (FAILED(hr))
	{
		Logger::Log(hr, "CreateRenderTargetView failed.");
		return false;
	}

	_deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), NULL);

	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = width;
	viewport.Height = height;

	_deviceContext->RSSetViewports(1, &viewport);

	return true;
}

bool Graphics::InitShaders()
{
	std::wstring shaderFolder;
#pragma region ShaderPath
	if (IsDebuggerPresent() == TRUE)
	{
#ifdef _DEBUG
	#ifdef _WIN64
		shaderFolder = L"../Bin/x64/Debug/";
	#else
		shaderFolder = L"../Bin/x86/Debug/";
	#endif
#else
	#ifdef _WIN64
		shaderFolder = L"../Bin/x64/Release/";
	#else
		shaderFolder = L"../Bin/x86/Release/";
	#endif
#endif
	}
#pragma endregion

	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	UINT numElements = ARRAYSIZE(layout);

	if (!_vertexShader.Initialize(_device, shaderFolder + L"vertexshader.cso", layout, numElements))
	{
		return false;
	}
	
	if (!_pixelShader.Initialize(_device, shaderFolder + L"pixelshader.cso"))
	{
		return false;
	}

	return true;
}