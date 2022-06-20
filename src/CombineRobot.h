#include "Cuboid.h"
#include "Cylinder.h"
#include <vector>
#include "Events.h"
#include "Model.h"
#include "Wheel2.h"
#include "Camera.h"

#pragma once

class CombineRobot {
private:
    Events* events;
private:
    Model* self;
    Model* leftFrontWheel;
    Model* rightFrontWheel;
    Model* leftBackWheel;
    Model* rightBackWheel;
public:
    double wheelAngle;
public:
    Vec3 pos;
    Vec3 relPos;
    Vec3 posBB; // posBackBuffer;
    Rotation rotate;
    Vec3 size;
    Vec3 facing;
    double speed;
    double scale;
private:
    int called = 0;
    bool mode = 1;
public:
    CombineRobot(double scale = 1, Vec3 pos = {0, 0, 0});
    ~CombineRobot();
    void update();
    void render();
private:
    void drive(double v);
    void turn(double v);
    void updatePhysics();
};
