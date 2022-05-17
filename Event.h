#pragma once

#include "KeyboardEvent.h"
#include "MouseEvent.h"

class Event
{
public:
	Event();
	~Event() = default;

	KeyboardEvent keyboard;
	MouseEvent mouse;
};

