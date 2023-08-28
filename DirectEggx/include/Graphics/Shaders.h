#pragma once
#include "logger/Logger.h"
#include <d3d11.h>
#include <wrl/client.h>
#include <d3dcompiler.h>

class VertexShader 
{
public:
	bool Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderPath);
	ID3D11VertexShader* GetShader();
	ID3D10Blob* GetBuffer();
private:
	Microsoft::WRL::ComPtr<ID3D11VertexShader> _shader = nullptr;
	Microsoft::WRL::ComPtr<ID3D10Blob> _shader_buffer = nullptr;
};
