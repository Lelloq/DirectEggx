#include "Input/MouseEvent.h"

MouseEvent::MouseEvent() : _type(EventType::Invalid), _x(0), _y(0)
{
}

MouseEvent::MouseEvent(const EventType type, const int x, const int y) : _type(type), _x(x), _y(y)
{
}