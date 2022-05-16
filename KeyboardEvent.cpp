#include "KeyboardEvent.h"
#include <GL/freeglut_std.h>

bool Key::isPressed() {
	return state;
}

void KeyboardEvent::basicKeysDown(unsigned char key, int x, int y) {

	if (key == 'w') key_w.state = true;
	if (key == 's') key_s.state = true;
	if (key == 'a') key_a.state = true;
	if (key == 'd') key_d.state = true;

}

void KeyboardEvent::basicKeysUp(unsigned char key, int x, int y) {

	if (key == 'w') key_w.state = false;
	if (key == 's') key_s.state = false;
	if (key == 'a') key_a.state = false;
	if (key == 'd') key_d.state = false;

}

void KeyboardEvent::specialKeysDown(int key, int x, int y) {

	if (key == GLUT_KEY_UP) key_up.state = true;
	if (key == GLUT_KEY_DOWN) key_down.state = true;
	if (key == GLUT_KEY_LEFT) key_left.state = true;
	if (key == GLUT_KEY_RIGHT) key_right.state = true;

}

void KeyboardEvent::specialKeysUp(int key, int x, int y) {

	if (key == GLUT_KEY_UP) key_up.state = false;
	if (key == GLUT_KEY_DOWN) key_down.state = false;
	if (key == GLUT_KEY_LEFT) key_left.state = false;
	if (key == GLUT_KEY_RIGHT) key_right.state = false;

	/*if (key == GLUT_KEY_UP) xRot -= 5.0f;
	if (key == GLUT_KEY_DOWN) xRot += 5.0f;
	if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT) yRot += 5.0f;

	xRot = (const int)xRot % 360;
	yRot = (const int)yRot % 360;
	*/
}