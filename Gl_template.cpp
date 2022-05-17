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
#include "CONFIG.h"
#include "Event.h"
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
unsigned int texture[2];	// texture object

void renderScene();
void changeSize(int, int);
void refreshTimer(int);

void coordinateAxis(bool x, bool y, bool z, double length, bool arrows);

/* Project implementation */

#define normalizeAngle(angle) ((int)(100 * angle) % 36000 * .01f)

static GLfloat cameraX = BASE_CAMERA_X;
static GLfloat cameraY = BASE_CAMERA_Y;
static GLfloat cameraZ = BASE_CAMERA_Z;
static int cameraDistanceScale = 0;

void reloadCameraView();

Event* event;
CombineRobot* combineRobot;

void updateView(void);
void drawView();

/* ---------------------- */

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	int w = WINDOW_WIDTH;
	int h = WINDOW_HEIGHT;
	int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - w) / 2, (screenHeight - h) / 2);
	glutInitWindowSize(w, h);

	glutCreateWindow(lpszAppName);

    event = new Event();

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutTimerFunc(0,refreshTimer,0);

    glutKeyboardFunc([](unsigned char key, int x, int y) { event->keyboard.basicHandleDown(key, x, y); });
    glutKeyboardUpFunc([](unsigned char key, int x, int y) { event->keyboard.basicHandleUp(key, x, y); });
    glutSpecialFunc([](int key, int x, int y) { event->keyboard.specialHandleDown(key, x, y); });
    glutSpecialUpFunc([](int key, int x, int y) { event->keyboard.specialHandleUp(key, x, y); });
    glutMouseFunc([](int button, int state, int x, int y) { event->mouse.mouseHandle(button, state, x, y); });
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    combineRobot = new CombineRobot();

    glutMainLoop();

    delete combineRobot;
    delete event;

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

	//coordinateAxis(1,1,1, 1000, 0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    updateView();
    drawView();

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
    GLfloat nRange = BASE_RANGE;
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
    
    if (CAMERA_MODE) {

        // Establish perspective: 
        gluPerspective(60.0f, fAspect, 10.0, 1000);

        //gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
        gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, 0, 0, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    }
    else {

        if (w <= h) glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
        else glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
        glMatrixMode(GL_MODELVIEW);

    }
}

void refreshTimer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, refreshTimer, 0);
}

void coordinateAxis(bool x, bool y, bool z, double length, bool arrows) {
    if (x) {
        // xAxis - red
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0, 0.0f, 0.0f);
        glVertex3f(length, 0.0f, 0.0f);
        if (arrows) {
            glVertex3f(length, 0.0f, 0.0f);
            glVertex3f(0.95 * length, 0.05 * length, 0.0f);
            glVertex3f(length, 0.0f, 0.0f);
            glVertex3f(0.95 * length, -0.05 * length, 0.0f);
            glEnd();
            glFlush();
        }
    }
    if (y) {
        // yAxis - green
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0, 0.0f);
        glVertex3f(0.0, length, 0.0f);
        if (arrows) {
            glVertex3f(0.0, length, 0.0f);
            glVertex3f(0.05 * length, 0.95 * length, 0.0f);
            glVertex3f(0.0, length, 0.0f);
            glVertex3f(-0.05 * length, 0.95 * length, 0.0f);
            glEnd();
            glFlush();
        }
    }
    if (z) {
        // zAxis - blue
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0f, 0);
        glVertex3f(0.0, 0.0f, length);
        if (arrows) {
            glVertex3f(0.0, 0.0f, length);
            glVertex3f(0.0, 0.05 * length, 0.95 * length);
            glVertex3f(0.0, 0.0f, length);
            glVertex3f(0.0, -0.05 * length, 0.95 * length);
            glEnd();
            glFlush();
        }
    }
}

void reloadCameraView() {
    if (CAMERA_MODE) {
        if (cameraDistanceScale > MAX_CAMERA_DISTANCE_SCALE) cameraDistanceScale = MAX_CAMERA_DISTANCE_SCALE;
        if (cameraDistanceScale < MIN_CAMERA_DISTANCE_SCALE) cameraDistanceScale = MIN_CAMERA_DISTANCE_SCALE;
        cameraZ = BASE_CAMERA_Z + CAMERA_DISTANCE_STEP * cameraDistanceScale;
        cameraX = cameraZ * BASE_CAMERA_X / BASE_CAMERA_Z;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0f, (GLfloat)lastWidth / (GLfloat)lastHeight, 10.0, 1000);
        gluLookAt(cameraX, cameraY, cameraZ, 0, 0, 0, 0, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}

void updateView() {
    GLdouble moveStep = 10 / FPS;
    GLfloat angleStep = 4 / FPS;

    if (event->keyboard.key_left.isScrolled()) {
        xRot -= angleStep;
        xRot = normalizeAngle(xRot);
    }
    if (event->keyboard.key_right.isScrolled()) {
        xRot += angleStep;
        xRot = normalizeAngle(xRot);
    }
    if (event->keyboard.key_up.isScrolled()) {
        yRot -= angleStep;
        xRot = normalizeAngle(yRot);
    }
    if (event->keyboard.key_down.isScrolled()) {
        yRot += angleStep;
        xRot = normalizeAngle(yRot);
    }

    if (event->mouse.scroll_up.isScrolled()) {
        cameraDistanceScale--;
        reloadCameraView();
    }

    if (event->mouse.scroll_down.isScrolled()) {
        cameraDistanceScale++;
        reloadCameraView();
    }

    if (event->keyboard.key_w.isScrolled() && !event->keyboard.key_s.isScrolled()) {
        combineRobot->move(moveStep * 2, 0);
    }
    if (event->keyboard.key_s.isScrolled() && !event->keyboard.key_w.isScrolled()) {
        combineRobot->move(-moveStep * 2, 0);
    }
    if (event->keyboard.key_a.isScrolled() && !event->keyboard.key_d.isScrolled()) {
        combineRobot->move(0, -moveStep);
    }
    if (event->keyboard.key_d.isScrolled() && !event->keyboard.key_a.isScrolled()) {
        combineRobot->move(0, moveStep);
    }

    glutPostRedisplay();
}

void drawView() {
	combineRobot->draw();
}