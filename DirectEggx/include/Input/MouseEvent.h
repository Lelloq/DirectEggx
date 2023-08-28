#pragma once

struct MousePoint
{
	int x;
	int y;
};

class MouseEvent
{
public:
	enum EventType
	{
		LPress = 0, LRelease,
		RPress, RRelease,
		MPress, MRelease,
		WheelUp, WheelDown,
		Move, RAW_MOVE,
		Invalid
	};
private:
	EventType _type;
	int _x, _y;
public:
	MouseEvent();
	MouseEvent(const EventType type, const int x, const int y);
	[[nodiscard]] inline bool		IsValid()		 const { return _type != EventType::Invalid; };
	[[nodiscard]] inline EventType  GetType()		 const { return _type; };
	[[nodiscard]] inline MousePoint GetPos()		 const { return { _x, _y }; };
	[[nodiscard]] inline int		GetPosX()		 const { return _x; };
	[[nodiscard]] inline int		GetPosY()		 const { return _y; };
};
