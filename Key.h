#pragma once

/**
 * Structure handling the information about single keyboard's key
 */
typedef struct Key {
	bool state = false;
	bool isScrolled() const;
} Key;

