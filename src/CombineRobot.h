#include "Cuboid.h"
#include "Cylinder.h"
#include <vector>
#include "Wheel.h"
#include "Events.h"

#pragma once

class CombineRobot {
public:
    Vec3 absolutePos;
    Vec3 relativePos;
    Rotation rotate;
private:
    Events* events;
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
    bool mode = 1;
    double scale;

public:
    CombineRobot(double scale = 1, Vec3 pos = {0, 0, 0});
    ~CombineRobot();
    void drive(double v);
    void turnY(double v);
    void update();
    void render();
};
