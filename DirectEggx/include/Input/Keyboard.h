#pragma once
#include "KeyboardEvent.h"
#include <queue>

class Keyboard
{
public:
	Keyboard();
	[[nodiscard]] inline bool IsKeyPressed(const unsigned char keycode) { return _keyStates[keycode]; };
	[[nodiscard]] inline bool IsKeyBufferEmpty()						{ return _keyBuffer.empty(); };
	[[nodiscard]] inline bool IsCharBufferEmpty()						{ return _charBuffer.empty(); };
	[[nodiscard]] KeyboardEvent ReadKey();								
	[[nodiscard]] unsigned char ReadChar();								
	void OnKeyPressed(const unsigned char key);							
	void OnKeyReleased(const unsigned char key);						
	void OnChar(const unsigned char key);								
	inline void EnableAutoRepeatKeys()									{ _autoRepeatKeys = true; }
	inline void DisableAutoRepeatKeys()									{ _autoRepeatKeys = false; }
	inline void EnableAutoRepeatChars()									{ _autoRepeatChars = true; }
	inline void DisableAutoRepeatChars()								{ _autoRepeatChars = false; }
	[[nodiscard]] inline const bool IsKeysAutoRepeat()					{ return _autoRepeatKeys; }
	[[nodiscard]] inline const bool IsCharsAutoRepeat()					{ return _autoRepeatChars; }
private:
	bool _autoRepeatKeys = false;
	bool _autoRepeatChars = false;
	bool _keyStates[256];
	std::queue<KeyboardEvent> _keyBuffer;
	std::queue<unsigned char> _charBuffer;
};
