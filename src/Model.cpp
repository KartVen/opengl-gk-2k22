#include "Model.h"
#include <iostream>
#include <iostream>

Model::Model(const char* fileName, double scale, Vec3 pos)
{
    this->pos = pos;
    this->scale = scale;
    this->load(fileName);
}

void Model::load(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Model::File not open..\n");
        return;
    }
    while (1)
    {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) break;
        if (strcmp(lineHeader, "v") == 0)
        {
            float vertexCoord[3];
            int fOut = fscanf(file, "%f %f %f\n", &vertexCoord[0], &vertexCoord[1], &vertexCoord[2]);
            Vec3 vertex = { vertexCoord[0], vertexCoord[1], vertexCoord[2] };
            vs.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vt") == 0)
        {
            float vertexCoord[2];
            int fOut = fscanf(file, "%f %f\n", &vertexCoord[0], &vertexCoord[1]);
            Vec2 vertex = { vertexCoord[0], vertexCoord[1] };
            vts.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vn") == 0) {
            float vertexCoord[3];
            int fOut = fscanf(file, "%f %f %f\n", &vertexCoord[0], &vertexCoord[1], &vertexCoord[2]);
            Vec3 vertex = { vertexCoord[0], vertexCoord[1], vertexCoord[2] };
            vns.push_back(vertex);
        }
        else if (strcmp(lineHeader, "f") == 0)
        {
            unsigned int vsIndex[3], vtsIndex[3], vnsIndex[3];
            int fOut = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                &vsIndex[0], &vtsIndex[0], &vnsIndex[0],
                &vsIndex[1], &vtsIndex[1], &vnsIndex[1],
                &vsIndex[2], &vtsIndex[2], &vnsIndex[2]
            );
            Face face = {
                {  vsIndex[0],  vsIndex[1],  vsIndex[2] },
                { vtsIndex[0], vtsIndex[1], vtsIndex[2] },
                { vnsIndex[0], vnsIndex[1], vnsIndex[2] },
            };
            fs.push_back(face);
        }
    }
    fclose(file);
    std::cout << "Model::loaded - " << fileName << '\n';
    std::cout << "vs:" << vs.size() << " vts:" << vts.size() << " vns:" << vns.size() << " fs:" << fs.size() << '\n';
}

void Model::render()
{
    for (const Face& face : fs) {
        Vec3 vertex1 = vs.at(face.v.x1 - 1) * scale;
        Vec3 vertex2 = vs.at(face.v.x2 - 1) * scale;
        Vec3 vertex3 = vs.at(face.v.x3 - 1) * scale;
        vertex1 = vertex1 + pos;
        vertex2 = vertex2 + pos;
        vertex3 = vertex3 + pos;

        glBegin(GL_TRIANGLES);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        glEnd();
    }
}
