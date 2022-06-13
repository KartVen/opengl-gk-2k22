# pragma once

#include "Base.h"
#include <vector>
#include "Textures.h"

typedef struct Face
{
	Triangle v;
	Triangle vt;
	Triangle vn;
	int material = 0;
};

typedef struct Material {
	std::string name;
	float alpha = 0;
	float ns = 0;
	float ni = 0;
	Vec3 ka; // ambient
	Vec3 kd; // diffuse
	Vec3 ks; // specular
	int illum = 0;
	int texture = -1;
	Material(
		const char* name,
		float alpha,
		float ns,
		float ni,
		Vec3 ka,
		Vec3 kd,
		Vec3 ks,
		int illum,
		int texture
	) {
		this->name = name;
		this->alpha = alpha;
		this->ns = ns;
		this->ni = ni;
		this->ka = ka;
		this->kd = kd;
		this->ks = ks;
		this->illum = illum;
		this->texture = texture;
	}
};

class Model
{
private:
	bool isInit = false;
	Vec3 pos;
	std::vector <Vec3> vs;
	std::vector <Vec2> vts;
	std::vector <Vec3> vns;
	std::vector <Face> fs;
	std::vector <unsigned int> texture;
	std::vector <unsigned int> lists;
	std::vector <Material*> materials;
	bool isMaterial = true;
	bool isNormal = true; // when model haven't got normals
	bool isTexture = true;
public:
	double scale = 1.;
	Color color;
public:
	Model();
	Model(std::string folderPath, std::string fileName, double scale, Vec3 pos = { 0.,0.,0. });
    void load(std::string folderPath, std::string fileName);
	void render();
private:
	void loadMaterial(std::string folderPath, std::string fileName);
	unsigned int loadTexture(std::string folderPath, std::string fileName);
};
