#include "Input/KeyboardEvent.h"

KeyboardEvent::KeyboardEvent() : _type(EventType::Invalid), _key(0u)
{
}

KeyboardEvent::KeyboardEvent(const EventType type, const unsigned char key) : _type(type), _key(key)
{
}
