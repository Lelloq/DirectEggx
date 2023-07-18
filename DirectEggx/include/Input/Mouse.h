#pragma once
#include "MouseEvent.h"
#include <queue>

class Mouse
{
public:
	void OnLeftPressed(int x, int y);
	void OnLeftReleased(int x, int y);
	void OnRightPressed(int x, int y);
	void OnRightReleased(int x, int y);
	void OnMiddlePressed(int x, int y);
	void OnMiddleReleased(int x, int y);
	void OnWheelUp(int x, int y);
	void OnWheelDown(int x, int y);
	void OnMouseMove(int x, int y);
	void OnMouseMoveRaw(int x, int y);

	[[nodiscard]] inline bool IsLeftDown()		   { return _isLeftDown; };
	[[nodiscard]] inline bool IsMiddleDown()	   { return _isMiddleDown; };
	[[nodiscard]] inline bool IsRightDown()		   { return _isRightDown; };

	[[nodiscard]] inline int GetPosX()			   { return _x; };
	[[nodiscard]] inline int GetPosY()			   { return _y; };
	[[nodiscard]] inline MousePoint GetPos()	   { return { _x, _y }; };

	[[nodiscard]] inline bool IsEventBufferEmpty() { return _eventBuffer.empty(); };
	[[nodiscard]] MouseEvent ReadEvent();

private:
	std::queue<MouseEvent> _eventBuffer;
	bool _isLeftDown = false;
	bool _isMiddleDown = false;
	bool _isRightDown = false;
	int _x = 0, _y = 0;
};
