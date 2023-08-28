#pragma once

class KeyboardEvent
{
public:
	enum EventType
	{
		Press = 0, Release, Invalid
	};

	KeyboardEvent();
	KeyboardEvent(const EventType type, const unsigned char key);
	inline bool IsPress()	 const { return _type == EventType::Press; };
	inline bool IsReleased() const { return _type == EventType::Release; };
	inline bool	IsValid()    const { return _type != EventType::Invalid; };
	inline unsigned char GetKeycode() const { return _key; };
private:
	EventType _type;
	unsigned char _key;
};
