#include "MouseEvent.h"
#include <GL/freeglut_std.h>

#define MOUSE_SCROLL_UP 0x0003
#define MOUSE_SCROLL_DOWN 0x0004

std::ostream& operator<<(std::ostream& os, const MouseXY& obj)
{
	os << obj.x << ":" << obj.y;
	return os;
}

bool Scroll::isScrolled()
{
	if (!handled) {
		handled = true;
		return handled;
	}
	return state;
}

void MouseEvent::mouseHandle(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON) {
		left_btn.state = !state;
	}

	if (button == GLUT_RIGHT_BUTTON) {
		right_btn.state = !state;
	}

	if (button == MOUSE_SCROLL_UP) {
		scroll_up.state = !state;
		scroll_up.handled = false;
	}

	if (button == MOUSE_SCROLL_DOWN) {
		scroll_down.state = !state;
		scroll_down.handled = false;
	}

	pos = { x,y };
}
