#include "Textures.h"

Textures* Textures::selfInstance = nullptr;

Textures::Textures() {
    data = {};
}

void Textures::initTextures()
{
    if (selfInstance == nullptr) selfInstance = new Textures();
}

Textures* Textures::getTextures()
{
    if (selfInstance == nullptr) initTextures();
    return selfInstance;
}

void Textures::destroyTextures()
{
    delete selfInstance;
    selfInstance = nullptr;
}


