#pragma once
#include "Blocks.h"
class Cylinder :
    public Blocks
{
public:
    Size2 size;
    int density;
    float sectorScale;
    char startAxe;
    Cylinder(Position center, Size2 size, Color color, int density = 40, float sectorScale = 1.0);
    Cylinder(Position center, Size2 size, Color color, char startAxe, int density = 40, float sectorScale = 1.0);
    ~Cylinder() = default;
    void setAxe(char axe);
    void draw();
};

