#pragma once
#include "KeyboardEvent.h"

class Event
{
public:
	KeyboardEvent keyboard;
	Event();
	~Event() = default;
};

