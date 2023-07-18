#pragma once
#include "Input/Mouse.h"

void Mouse::OnLeftPressed(int x, int y)
{
	_isLeftDown = true;
	MouseEvent e(MouseEvent::EventType::LPress, x, y);
	_eventBuffer.push(e);
}

void Mouse::OnLeftReleased(int x, int y)
{
	_isLeftDown = false;
	MouseEvent e(MouseEvent::EventType::LRelease, x, y);
}

void Mouse::OnRightPressed(int x, int y)
{
	_isRightDown = true;
	MouseEvent e(MouseEvent::EventType::RPress, x, y);
	_eventBuffer.push(e);
}

void Mouse::OnRightReleased(int x, int y)
{
	_isRightDown = false;
	MouseEvent e(MouseEvent::EventType::RRelease, x, y);
}

void Mouse::OnMiddlePressed(int x, int y)
{
	_isMiddleDown = true;
	MouseEvent e(MouseEvent::EventType::MPress, x, y);
	_eventBuffer.push(e);
}

void Mouse::OnMiddleReleased(int x, int y)
{
	_isMiddleDown = false;
	MouseEvent e(MouseEvent::EventType::MRelease, x, y);
}

void Mouse::OnWheelUp(int x, int y)
{
	_eventBuffer.push(MouseEvent(MouseEvent::EventType::WheelUp, x, y));
}

void Mouse::OnWheelDown(int x, int y)
{
	_eventBuffer.push(MouseEvent(MouseEvent::EventType::WheelDown, x, y));
}

void Mouse::OnMouseMove(int x, int y)
{
	_x = x;
	_y = y;
	_eventBuffer.push(MouseEvent(MouseEvent::EventType::Move, x, y));
}

void Mouse::OnMouseMoveRaw(int x, int y)
{
	_eventBuffer.push(MouseEvent(MouseEvent::EventType::RAW_MOVE, x, y));
}

MouseEvent Mouse::ReadEvent()
{
	if (_eventBuffer.empty()) return MouseEvent();
	else
	{
		MouseEvent e = _eventBuffer.front();
		_eventBuffer.pop();
		return e;
	}
}
