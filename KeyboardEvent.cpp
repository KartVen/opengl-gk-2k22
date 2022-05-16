#include "KeyboardEvent.h"

bool Key::isPressed() {
	return state;
}

Key::Key(char name) {
	this->name = name;
}
