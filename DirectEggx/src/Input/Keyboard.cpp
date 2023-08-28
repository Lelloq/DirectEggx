#include "Input/Keyboard.h"

Keyboard::Keyboard()
{
	for (int i = 0; i < 256; i++)
	{
		_keyStates[i] = false;
	}
}

KeyboardEvent Keyboard::ReadKey()
{
	if (_keyBuffer.empty()) return KeyboardEvent();
	KeyboardEvent e = _keyBuffer.front();
	_keyBuffer.pop();
	return e;
}

unsigned char Keyboard::ReadChar()
{
	if (_charBuffer.empty()) return 0u;
	unsigned char c = _charBuffer.front();
	_charBuffer.pop();
	return c;
}

void Keyboard::OnKeyPressed(const unsigned char key)
{
	_keyStates[key] = true;
	_keyBuffer.push(KeyboardEvent(KeyboardEvent::EventType::Press, key));
}

void Keyboard::OnKeyReleased(const unsigned char key)
{
	_keyStates[key] = false;
	_keyBuffer.push(KeyboardEvent(KeyboardEvent::EventType::Release, key));
}

void Keyboard::OnChar(const unsigned char key)
{
	_charBuffer.push(key);
}