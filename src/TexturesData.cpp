#include "TexturesData.h"

TexturesData* TexturesData::selfInstance = nullptr;

TexturesData::TexturesData() {
    data = {};
}

void TexturesData::init()
{
    if (selfInstance == nullptr) selfInstance = new TexturesData();
}

TexturesData* TexturesData::getTexturesInfo()
{
    return selfInstance;
}

void TexturesData::destroy()
{
    delete selfInstance;
}


