#include "OBJModel.h"

OBJModel::OBJModel()
{
    scale = 1;
}

void OBJModel::load(const char* filename)
{
    FILE* file = fopen(filename, "r");

    while (1)
    {

        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) break;
        if (strcmp(lineHeader, "v") == 0)
        {
            Vec3 vertex;
            int fOut = fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertexPoss.push_back(vertex);
        }
        if (strcmp(lineHeader, "f") == 0)
        {
            int smietnik;
            Face tempface;
            int fOut = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &tempface.v.x1, &tempface.vt.x1, &smietnik, &tempface.v.x2, &tempface.vt.x2, &smietnik, &tempface.v.x3, &tempface.vt.x3, &smietnik);
            faces.push_back(tempface);
        }
        if (strcmp(lineHeader, "vt") == 0)
        {
            Vec2 vertex;
            int fOut = fscanf(file, "%f %f\n", &vertex.x, &vertex.y);
            vertexTexs.push_back(vertex);
        }
    }
    fclose(file);
}

void OBJModel::render()
{
    for (int i = 0; i < faces.size(); i++)
    {
        //glColor3f(0.3f + 0.5 * float(i % 2), 1.0f, 0.3f + 0.5 * float(i % 2));
        //glBindTexture(GL_TEXTURE_2D, texture[texture_id]);
        //glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
        Vec3 t1[3] = {
            vertexPoss.at((faces.at(i).v.x1) - 1),
            vertexPoss.at((faces.at(i).v.x2) - 1),
            vertexPoss.at((faces.at(i).v.x3) - 1)
        };
        GLfloat x1[3] = { t1[0].x * scale + pos.x, (t1[0].y * scale) + pos.y, t1[0].z * scale + pos.z };
        GLfloat x2[3] = { t1[1].x * scale + pos.x, (t1[1].y * scale) + pos.y, t1[1].z * scale + pos.z };
        GLfloat x3[3] = { t1[2].x * scale + pos.x, (t1[2].y * scale) + pos.y, t1[2].z * scale + pos.z };
        /*vek2 tex[3] = {
            verticesT.at((faces.at(i).vt.x1) - 1),
            verticesT.at((faces.at(i).vt.x2) - 1),
            verticesT.at((faces.at(i).vt.x3) - 1)
        };*/
        /*GLdouble tex1[2] = { tex[0].x,tex[0].y };
        GLdouble tex2[2] = { tex[1].x,tex[1].y };
        GLdouble tex3[2] = { tex[2].x,tex[2].y };*/

        glColor3f(1, 1, 1);
        /*glTexCoord2d(tex1[0], tex1[1]);*/ glVertex3d(x1[0], x1[1], x1[2]);
        /*glTexCoord2d(tex2[0], tex2[1]); */glVertex3d(x2[0], x2[1], x2[2]);
        /*glTexCoord2d(tex3[0], tex3[1]); */glVertex3d(x3[0], x3[1], x3[2]);
        glEnd();
        /*glDisable(GL_TEXTURE_2D);*/
    }
}
