#include "Cuboid.h"
#include "Cylinder.h"
#include <vector>
#include "Wheel.h"

#pragma once

class CombineRobot {
public:
    Vec3 pos;
private:
    Size size;
    Color basicColor;
    Color darkBasicColor;
    Color wheelColor;
    Color headerFrontColor;
    Color bayonetsColor;
    Color cabineColor;
    Color roofColor;
    Color glassColor;
    
    std::vector<Blocks*> headerPart;
    std::vector<Cuboid*> frontPart;
    std::vector<Cuboid*> middlePart;
    std::vector<Cuboid*> backPart;
    std::vector<Wheel*> frontWheelPart;
    std::vector<Wheel*> backWheelPart;

    int called = 0;

public:
    CombineRobot(GLfloat x = 0, GLfloat y = 0, GLfloat z = 0);
    ~CombineRobot();
    void render();
    void move(GLdouble x, GLdouble y);
};
