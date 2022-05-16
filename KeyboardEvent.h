#pragma once

/**
 * Structure handlingteh information about single keyboard's key
 */
typedef struct Key {
	char name;
	bool state = false;
	bool isPressed();
	Key(char name);
} Key;


/**
 * Class holding the states of the keyboard keys
 */
class KeyboardEvent
{
private:
	friend class Event;
	~KeyboardEvent() = default;
public:
	Key key_a{ 'A' };
	Key key_d{ 'D' };
	Key key_s{ 'S' };
	Key key_w{ 'W' };
};

