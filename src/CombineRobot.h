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
    Wheel2* leftFrontWheel;
    Wheel2* rightFrontWheel;
    Wheel2* leftBackWheel;
    Wheel2* rightBackWheel;
public:
    double wheelAngle;
public:
    Vec3 pos;
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
