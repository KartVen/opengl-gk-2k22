#pragma once

/**
 * Structure handlingteh information about single keyboard's key
 */
typedef struct Key {
	bool state = false;
	bool isPressed();
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
	Key key_a;
	Key key_d;
	Key key_s;
	Key key_w;
	Key key_up;
	Key key_down;
	Key key_left;
	Key key_right;
	void basicKeysDown(unsigned char key, int x, int y);
	void basicKeysUp(unsigned char key, int x, int y);
	void specialKeysDown(int key, int x, int y);
	void specialKeysUp(int key, int x, int y);
};

