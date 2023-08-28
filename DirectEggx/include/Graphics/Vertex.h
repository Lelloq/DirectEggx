#pragma once
#include <DirectXMath.h>

struct Vertex
{
	Vertex() {}
	Vertex(float x, float y, float r, float g, float b, float a) : 
		_pos(x, y), 
		_colour(r,g,b,a)
	{}

	DirectX::XMFLOAT2 _pos;
	DirectX::XMFLOAT4 _colour;
};
