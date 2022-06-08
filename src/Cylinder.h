#pragma once
#include "Blocks.h"
#include <math.h>


class Cylinder :
    public Blocks
{
public:
    Size2 size;
    int density;
    float sectorScale;
    char startAxe;
    Cylinder(Vec3 center, Size2 size, Color color, int density = 40, float sectorScale = 1.0);
    Cylinder(Vec3 center, Size2 size, Color color, char startAxe, int density = 40, float sectorScale = 1.0);
    ~Cylinder() = default;
    void setAxe(char axe);
    void render(Vec3 pos = { 0,0,0 });
};

