#pragma once
#include "Base.h"
#include <sstream>
#include <fstream>


static ObjectStruct OBJLoad(const char* fileName)
{

	std::stringstream ss;
	std::ifstream objFile(fileName);

	if (!objFile.is_open()) throw "OBJLoader::Could not open file.";
	std::string line = "";
	std::string prefix = "";
	Vec3 tempVec3;
	Vec2 tempVec2;
	ObjectStruct newObject;

	while (std::getline(objFile, line))
	{
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "v")
		{
			ss >> tempVec3.x >> tempVec3.y >> tempVec3.z;
			newObject.vertexPoss.push_back(tempVec3);
		}
		else if (prefix == "vt")
		{
			ss >> tempVec2.x >> tempVec2.y;
			newObject.vertexTexs.push_back(tempVec2);
		}
		else if (prefix == "vn")
		{
			ss >> tempVec3.x >> tempVec3.y >> tempVec3.z;
			newObject.vertexNormals.push_back(tempVec3);
		}
		else if (prefix == "f")
		{
			int sign = 0;
			int xP = 1, xT = 1, xN = 1;
			Face newFace;
			while (ss >> sign)
			{
				if (sign == 0) {
					if (xP > 3) xP = 1;
					if (xP == 1) newFace.v.x1 = sign;
					if (xP == 2) newFace.v.x2 = sign;
					if (xP == 3) newFace.v.x3 = sign;
					xP++;
				}
				else if (sign == 1) {
					if (xT > 3) xT = 1;
					if (xT == 1) newFace.vt.x1 = sign;
					if (xT == 2) newFace.vt.x2 = sign;
					if (xT == 3) newFace.vt.x3 = sign;
					xT++;
				}
				else if (sign == 2) {
					if (xN > 3) xN = 1;
					if (xN == 1) newFace.vn.x1 = sign;
					if (xN == 2) newFace.vn.x2 = sign;
					if (xN == 3) newFace.vn.x3 = sign;
					xN++;
				}

				if (ss.peek() == '/')
				{
					++sign;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					++sign;
					ss.ignore(1, ' ');
				}

				if (sign > 2) sign = 0;
			}
			newObject.faces.push_back(newFace);
		}
	}
	return newObject;
};

static void OBJRender(Vec3 shiftPos, GLfloat scale, ObjectStruct ObjectStruct, Color color)
{
	for (int i = 0; i < ObjectStruct.faces.size(); i++)
	{
		//glBindTexture(GL_TEXTURE_2D, texture[texture_id]);
		//glEnable(GL_TEXTURE_2D);
		glBegin(GL_TRIANGLES);



		Vec3 t1[3] = { ObjectStruct.vertexPoss.at((ObjectStruct.faces.at(i).v.x1) - 1), ObjectStruct.vertexPoss.at((ObjectStruct.faces.at(i).v.x2) - 1),  ObjectStruct.vertexPoss.at((ObjectStruct.faces.at(i).v.x3) - 1) };
		GLfloat x1[3] = { t1[0].x * scale + shiftPos.x, (t1[0].y * scale) + shiftPos.y ,t1[0].z * scale + shiftPos.z };
		GLfloat x2[3] = { t1[1].x * scale + shiftPos.x, (t1[1].y * scale) + shiftPos.y ,t1[1].z * scale + shiftPos.z };
		GLfloat x3[3] = { t1[2].x * scale + shiftPos.x, (t1[2].y * scale) + shiftPos.y,t1[2].z * scale + shiftPos.z };
		Vec2 tex[3] = { ObjectStruct.vertexTexs.at((ObjectStruct.faces.at(i).vt.x1) - 1),ObjectStruct.vertexTexs.at((ObjectStruct.faces.at(i).vt.x2) - 1),ObjectStruct.vertexTexs.at((ObjectStruct.faces.at(i).vt.x3) - 1) };
		GLdouble tex1[2] = { tex[0].x,tex[0].y };
		GLdouble tex2[2] = { tex[1].x,tex[1].y };
		GLdouble tex3[2] = { tex[2].x,tex[2].y };

		/*glTexCoord2d(tex1[0], tex1[1]); */ glVertex3d(x1[0], x1[1], x1[2]);
		/*glTexCoord2d(tex2[0], tex2[1]); */ glVertex3d(x2[0], x2[1], x2[2]);
		/*glTexCoord2d(tex3[0], tex3[1]); */ glVertex3d(x3[0], x3[1], x3[2]);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
}
