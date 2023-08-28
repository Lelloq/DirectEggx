#include "Graphics/Shaders.h"

bool VertexShader::Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderPath)
{
	HRESULT hr = D3DReadFileToBlob(shaderPath.c_str(), _shader_buffer.GetAddressOf());
	if FAILED(hr)
	{
		std::wstring msg = L"Failed to load shader: ";
		msg += shaderPath;
		Logger::Log(hr, msg);
		return false;
	}

	hr = device->CreateVertexShader(_shader_buffer.Get()->GetBufferPointer(), _shader_buffer->GetBufferSize(), NULL, _shader.GetAddressOf());
	if FAILED(hr)
	{
		std::wstring msg = L"Failed to create vertex shader: ";
		msg += shaderPath;
		Logger::Log(hr, msg);
		return false;
	}

	return true;
}

ID3D11VertexShader* VertexShader::GetShader()
{
	return _shader.Get();
}

ID3D10Blob* VertexShader::GetBuffer()
{
	return _shader_buffer.Get();
}
