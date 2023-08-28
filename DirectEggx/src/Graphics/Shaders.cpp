#include "Graphics/Shaders.h"

bool VertexShader::Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderPath, D3D11_INPUT_ELEMENT_DESC* layoutDesc, UINT numElements)
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

	hr = device->CreateInputLayout(
		layoutDesc, numElements,
		_shader_buffer->GetBufferPointer(), _shader_buffer->GetBufferSize(),
		_inputLayout.GetAddressOf());

	if (FAILED(hr))
	{
		Logger::Log(hr, "Failed to create input layout");
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

ID3D11InputLayout* VertexShader::GetInputLayout()
{
	return _inputLayout.Get();
}

bool PixelShader::Initialize(Microsoft::WRL::ComPtr<ID3D11Device>& device, std::wstring shaderPath)
{
	HRESULT hr = D3DReadFileToBlob(shaderPath.c_str(), _shader_buffer.GetAddressOf());
	if FAILED(hr)
	{
		std::wstring msg = L"Failed to load shader: ";
		msg += shaderPath;
		Logger::Log(hr, msg);
		return false;
	}

	hr = device->CreatePixelShader(_shader_buffer.Get()->GetBufferPointer(), _shader_buffer->GetBufferSize(), NULL, _shader.GetAddressOf());
	if FAILED(hr)
	{
		std::wstring msg = L"Failed to create pixel shader: ";
		msg += shaderPath;
		Logger::Log(hr, msg);
		return false;
	}

	return true;
}

ID3D11PixelShader* PixelShader::GetShader()
{
	return _shader.Get();
}

ID3D10Blob* PixelShader::GetBuffer()
{
	return _shader_buffer.Get();
}
