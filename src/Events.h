#pragma once

typedef struct MousePos {
	int x = 0;
	int y = 0;
};

typedef struct Key {
	int state = -1;
	int key = -1;
	MousePos cursor;
};

class Events
{
private:
	static Events* selfInstance;
public:
	Key basicKey;
	Key specialKey;
	Key mouseKey;
	MousePos mousePos;
	const short int down = 0;
	const short int up = 1;
private:
	Events();
	~Events() = default;
public:
	static void initEvents();
	static Events* getEvents();
	static void destroyEvents();
	void reset();
};

