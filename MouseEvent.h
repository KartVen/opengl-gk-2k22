#pragma once
#include "Key.h"
#include <ostream>

typedef struct MouseXY {
	int x = 0, y = 0;
	friend std::ostream& operator<<(std::ostream& os, const MouseXY& obj);
} pos;

typedef struct Scroll {
	bool state = false;
	bool isScrolled();
private:
	friend class MouseEvent;
	bool handled = true;
};

class MouseEvent
{
private:
	friend class Event;
	MouseEvent() = default;
	~MouseEvent() = default;
public:
	Key left_btn;
	Key right_btn;
	Scroll scroll_up;
	Scroll scroll_down;
	MouseXY pos;
	void mouseHandle(int button, int state, int x, int y);
};

