#pragma once
#include "Events.h"
#include "Model.h"
#include "Base.h"
class Wheel2
{
private:
    Events* events;
private:
    Model* self;
public:
    Vec3 pos;
    Vec3 posBB; // posBackBuffer;
    Rotation rotate;
    Vec3 size;
private:
    int called = 0;
    bool mode = 1;
public:
    Wheel2(std::string folderPath, std::string fileName, double scale = 1, Vec3 pos = { 0, 0, 0 });
    ~Wheel2();
    void update();
    void render();
    void setModelAxePos(Vec3 pos);
private:
    void drive(double v);
    void turn(double v);
};

