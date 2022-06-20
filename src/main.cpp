// OpenGL GK 2k22 Project - Refactored

#include <GL/glut.h>
#include "DEFINES.h"
#include "Events.h"
#include "App.h"
#include <iostream>

// window
void changeSize(int w, int h);

// render
void renderDisplay(void);

// key events
void basicKeyDown(unsigned char key, int x, int y);
void basicKeyUp(unsigned char key, int x, int y);
void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);

// mouse events
void mouseMotion(int x, int y);
void mouseKey(int key, int state, int x, int y);

// special funcs
void coordinateAxis(bool x, bool y, bool z);

Events* events = nullptr;
App* app = nullptr;

int main(int argc, char** argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	int w = WIDTH;
	int h = HEIGHT;
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - w) / 2, (screenHeight - h) / 2);
	glutInitWindowSize(w, h);
	glutCreateWindow(TITLE);

	glutDisplayFunc(renderDisplay);
	glutIdleFunc(renderDisplay);
	glutReshapeFunc(changeSize);

	glutIgnoreKeyRepeat(1);

	glutKeyboardFunc(basicKeyDown);
	glutKeyboardUpFunc(basicKeyUp);
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);

	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	Events::initEvents();
	events = Events::getEvents();
	app = new App();
	glutMainLoop();

	delete app;
	Events::destroyEvents();
	events = nullptr;

	return 1;
}

void changeSize(int w, int h) {

	// Prevent a divide by zero
	if (h == 0) h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void coordinateAxis(bool x, bool y, bool z) {
	if (x) {
		// xAxis
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3d(0, 0, 0);
			glVertex3d(5000, 0, 0);
		glEnd();
	}
	if (y) {
		// yAxis
		glBegin(GL_LINES);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 5000, 0);
		glEnd();
	}
	if (z) {
		// zAxis
		glBegin(GL_LINES);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 0, 5000);
		glEnd();
	}
}

void basicKeyDown(unsigned char key, int x, int y) {
	events->basicKey = { 0, key, {x,y} };
}

void basicKeyUp(unsigned char key, int x, int y) {
	events->basicKey = { 1, key, {x,y} };
}

void specialKeyDown(int key, int x, int y) {
	events->specialKey = { 0, key, {x,y} };
}

void specialKeyUp(int key, int x, int y) {
	events->specialKey = { 1, key, {x,y} };
}

void mouseMotion(int x, int y) {
	events->mousePos = { x,y };
}

void mouseKey(int key, int state, int x, int y) {
	events->mouseKey = { state, key, {x,y} };
	events->mousePos = { x,y };
}

void renderDisplay(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	glPushMatrix();

	app->update();
	events->reset();
	
	app->render();

	glPopMatrix();

	glutSwapBuffers();
}