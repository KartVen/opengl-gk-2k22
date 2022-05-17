#pragma once
#include "Key.h"

/**
 * Class holding the states of the keyboard keys
 */
class KeyboardEvent
{
private:
	friend class Event;
	KeyboardEvent() = default;
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
	void basicHandleDown(unsigned char key, int x, int y);
	void basicHandleUp(unsigned char key, int x, int y);
	void specialHandleDown(int key, int x, int y);
	void specialHandleUp(int key, int x, int y);
};

