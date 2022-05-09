#pragma once
#include "Blocks.h"

class Cuboid :
    public Blocks
{
public:
    Size size;
    bool center;
    Cuboid(Position pos, Size size, Color color, bool center = false);
    ~Cuboid() = default;
    void draw();
};

