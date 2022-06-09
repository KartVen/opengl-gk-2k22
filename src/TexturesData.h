#pragma once
#include <vector>
#include <string>

typedef struct Texture {
	unsigned int textureID;
	std::string fileName;
};

class TexturesData
{
private:
	static TexturesData* selfInstance;
private:
	TexturesData();
	~TexturesData() = default;
public:
	std::vector<Texture> data;
public:
	static void init();
	static TexturesData* getTexturesInfo();
	static void destroy();
};

