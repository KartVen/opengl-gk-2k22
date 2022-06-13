#pragma once
#include <vector>
#include <string>

typedef struct Texture {
	unsigned int textureID = -1;
	std::string fileName = "";
};

class Textures
{
private:
	static Textures* selfInstance;
private:
	Textures();
	~Textures() = default;
public:
	std::vector<Texture> data;
public:
	static void initTextures();
	static Textures* getTextures();
	static void destroyTextures();
};

