#pragma once
#include "Blocks.h"

class Cuboid :
    public Blocks
{
public:
    Size size;
    bool center;
    Cuboid(Vec3 pos, Size size, Color color, bool center = false);
    ~Cuboid() = default;
    void render(Vec3 pos = { 0,0,0 });
};

