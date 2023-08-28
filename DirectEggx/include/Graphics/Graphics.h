#pragma once
#include "AdapterReader.h"
#include "Shaders.h"

class Graphics
{
public:
	bool Init(HWND hwnd, int width, int height);
	void RenderFrame();
private:
	bool InitDX(HWND hwnd, int width, int height);
	bool InitShaders();

	Microsoft::WRL::ComPtr<ID3D11Device>		   _device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>	   _deviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain>		   _swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _renderTargetView;

	PixelShader _pixelShader;
	VertexShader _vertexShader;
};
