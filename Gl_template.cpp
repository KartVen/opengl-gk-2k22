// Gl_template.c
// Counting error before "fopen"
#define  _CRT_SECURE_NO_WARNINGS

// Set text mode:
#ifdef _MSC_VER        // Check if MS Visual C compiler
#   ifndef _MBCS
#      define _MBCS    // Uses Multi-byte character set
#   endif
#   ifdef _UNICODE     // Not using Unicode character set
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <gl\glut.h>
#include <cmath>				// Define for sqrt
#include <stdio.h>
#include <string>
#include "CombineRobot.h"
#include <iostream>

#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// BMP format ID
#define GL_PI 3.14


// Color Palette handle
HPALETTE hPalette = NULL;

// Application name and instance storeage
static LPCTSTR lpszAppName = "GL Template";
static HINSTANCE hInstance;

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

static GLsizei lastHeight;
static GLsizei lastWidth;

// Texture description
BITMAPINFOHEADER bitmapInfoHeader;	// image header
unsigned char* bitmapData;			// texture data
unsigned int texture[2];			// texture object

void renderScene();
void changeSize(int, int);
void refreshTimer(int);

void normalKeys(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);

void coordinateAxis(bool x, bool y, bool z);

/* Project implementation */

CombineRobot* combineRobot;

void runView();

/* ---------------------- */

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	int w = 800;
	int h = 600;
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - w) / 2, (screenHeight - h) / 2);
	glutInitWindowSize(w, h);

	glutCreateWindow(lpszAppName);

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    //glutTimerFunc(0,refreshTimer,0);

    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    combineRobot = new CombineRobot();

    glutMainLoop();

    delete combineRobot;

    return 0;
}

void renderScene() {

	// Storage for calculated surface normal
    //float normal[3];

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Reset Matrix
    glLoadIdentity();

    // Save the matrix state and do the rotations
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    /////////////////////////////////////////////////////////////////
    // MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
    /////////////////////////////////////////////////////////////////

	coordinateAxis(1,1,1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    runView();

    // Drawing a rectangle
    //glRectd(-10.0,-10.0,20.0,20.0);

    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    glPopMatrix();
    //glMatrixMode(GL_MODELVIEW);

    // Flush drawing commands
    glFlush();
    
	glutSwapBuffers();
}

void changeSize(int w, int h) {
    GLfloat nRange = 300.0f;
    GLfloat fAspect;
    // Prevent a divide by zero
    if (h == 0)
		h = 1;

    lastWidth = w;
    lastHeight = h;

    fAspect = (GLfloat)w / (GLfloat)h;
    // Set Viewport to window dimensions
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
    else
        glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
    
    // Establish perspective: 
    //gluPerspective(60.0f,fAspect,1.0,1000);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
}

void refreshTimer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, refreshTimer, 0);
}

void normalKeys(unsigned char key, int x, int y) {}

void specialKeys(int key, int x, int y) {
    switch (key)
    {
        case GLUT_KEY_UP:
            xRot -= 5.0f;
            break;
        case GLUT_KEY_DOWN:
            xRot += 5.0f;
            break;
        case GLUT_KEY_LEFT:
            yRot -= 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            yRot += 5.0f;
            break;
    }

    xRot = (const int)xRot % 360;
    yRot = (const int)yRot % 360;

    glutPostRedisplay();
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

void runView() {
	combineRobot->draw();
}