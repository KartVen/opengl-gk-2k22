#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include "Base.h"

class OBJModel {
private:
    std::vector <Vec3> vertexPoss;
    std::vector <Vec2> vertexTexs;
    std::vector <Vec3> vertexNorms;
    std::vector <Face> faces;
public:
    Vec3 pos;
    double scale;
    OBJModel();
    ~OBJModel() = default;
    void load(const char* filename);
    void render();
};