#pragma once
#include <DirectXMath.h>

struct Vertex
{
	Vertex() {}
	Vertex(float x, float y) : _pos(x, y)
	{
	}

	DirectX::XMFLOAT2 _pos;
};
