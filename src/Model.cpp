#include "Model.h"
#include <iostream>
#include "DEFINES.h"

Model::Model() = default;

Model::Model(std::string folderPath, std::string fileName, double scale, Vec3 pos)
{
    this->pos = pos;
    this->scale = scale;
    this->load(folderPath, fileName);
    this->isInit = true;
}

void Model::load(std::string folderPath, std::string fileName)
{
    FILE* file = fopen((folderPath + fileName).c_str(), "r");
    if (file == NULL) {
        std::cout << "Model::File not open.. ("<< folderPath + fileName <<")\n";
        return;
    }
    int currentMaterial = 0;
    while (1)
    {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        const char* test = lineHeader;
        if (res == EOF) break;
        if (strcmp(lineHeader, "mtllib") == 0) {
            char fileMaterialName[200] = "";
            int fOut = fscanf(file, "%s\n", fileMaterialName);
            this->loadMaterial(folderPath, fileMaterialName);
            int bp = 0;
        }
        else if (strcmp(lineHeader, "usemtl") == 0) {
            char materialName[200] = "";
            int fOut = fscanf(file, "%s\n", materialName);
            int materialsSize = materials.size();
            for (int materialIndex = 0; materialIndex < materialsSize; materialIndex++) {
                if (strcmp(materials[materialIndex]->name.c_str(), materialName) == 0) {
                    currentMaterial = materialIndex;
                    break;
                }
            }
            int bp = 0;
        }
        else if (strcmp(lineHeader, "v") == 0)
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
                currentMaterial
            };
            fs.push_back(face);
        }
    }
    fclose(file);
    if (MODEL_DEBUG) {
        std::cout << "Model::loaded - " << folderPath + fileName << '\n';
        std::cout << " - vs:" << vs.size() << " vts:" << vts.size() << " vns:" << vns.size() << " fs:" << fs.size() << '\n';
    }
}

void Model::loadMaterial(std::string folderPath, std::string fileName)
{
    FILE* file = fopen((folderPath + fileName).c_str(), "r");
    if (file == NULL) {
        std:: cout << "Model::FileMaterial not open..\n";
        return;
    }
    int currentMaterial = -1;
    while (1)
    {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        const char* test = lineHeader;
        if (res == EOF) break;
        if (strcmp(lineHeader, "newmtl") == 0)
        {
            char materialName[200] = "";
            int fOut = fscanf(file, "%s\n", materialName);
            Vec3 clearVec = { 0,0,0 };
            materials.push_back(new Material(materialName, 0, 0, 0, clearVec, clearVec, clearVec, 0, -1));
            currentMaterial = materials.size() - 1;
        }
        if (currentMaterial == -1);
        else if (strcmp(lineHeader, "Ns") == 0)
        {
            float ns;
            int fOut = fscanf(file, "%f\n", &ns);
            materials.at(currentMaterial)->ns = ns;
        }
        else if (strcmp(lineHeader, "Ka") == 0)
        {
            float colorAxe[3];
            int fOut = fscanf(file, "%f %f %f\n", &colorAxe[0], &colorAxe[1], &colorAxe[2]);
            Vec3 colorSpec = { colorAxe[0], colorAxe[1], colorAxe[2] };
            materials.at(currentMaterial)->ka = colorSpec;
        }
        else if (strcmp(lineHeader, "Kd") == 0)
        {
            float colorAxe[3];
            int fOut = fscanf(file, "%f %f %f\n", &colorAxe[0], &colorAxe[1], &colorAxe[2]);
            Vec3 colorSpec = { colorAxe[0], colorAxe[1], colorAxe[2] };
            materials.at(currentMaterial)->kd = colorSpec;
        }
        else if (strcmp(lineHeader, "Ks") == 0)
        {
            float colorAxe[3];
            int fOut = fscanf(file, "%f %f %f\n", &colorAxe[0], &colorAxe[1], &colorAxe[2]);
            Vec3 colorSpec = { colorAxe[0], colorAxe[1], colorAxe[2] };
            materials.at(currentMaterial)->ks = colorSpec;
        }
        else if (strcmp(lineHeader, "Ni") == 0)
        {
            float ni;
            int fOut = fscanf(file, "%f\n", &ni);
            materials.at(currentMaterial)->ni = ni;
        }
        else if (strcmp(lineHeader, "illum") == 0)
        {
            int illum;
            int fOut = fscanf(file, "%d\n", &illum);
            materials.at(currentMaterial)->illum = illum;
        }
        else if (strcmp(lineHeader, "map_Kd") == 0)
        {
            char fileMapKdName[200] = "";
            int fOut = fscanf(file, "%s\n", &fileMapKdName);

            unsigned int textureID = -1;
            Textures* textures = Textures::getTextures();
            if (textures->data.size() == 0)
                textureID = this->loadTexture(folderPath, fileMapKdName);
            else for (auto& texture : textures->data)
                if (strcmp(texture.fileName.c_str(), fileMapKdName) == 0) textureID = texture.textureID;

            if (textureID == -1) textureID = this->loadTexture(folderPath, fileMapKdName);

            materials.at(currentMaterial)->texture = textureID;
        }
    }
    fclose(file);
    isMaterial = (materials.size() != 0) ? true : false;
    if (MODEL_DEBUG) {
        std::cout << "Model::loaded - " << folderPath + fileName << '\n';
        std::cout << " - materials:" << materials.size() << '\n';
    }
}

unsigned int Model::loadTexture(std::string folderPath, std::string fileName)
{
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;
    unsigned int width, height;
    unsigned char* data; // RGB data

    FILE* file = fopen((folderPath + fileName).c_str(), "rb");
    if (!file) {
        std::cout << fileName << " could not be opened..\n";
        return -1;
    }

    // Read the header, i.e. the 54 first bytes
    // If less than 54 bytes are read, problem
    if (fread(header, 1, 54, file) != 54) {
        std::cout << "Not a correct BMP file\n";
        fclose(file);
        return -1;
    }
    // check if BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        std::cout << "Not a correct BMP file\n";
        fclose(file);
        return -1;
    }
    // check 24bpp file
    if (*(int*)&(header[0x1E]) != 0) {
        std::cout << "Not a correct BMP file\n";
        fclose(file);
        return -1;
    }
    if (*(int*)&(header[0x1C]) != 24) {
        std::cout << "Not a correct BMP file\n";
        fclose(file);
        return -1;
    }

    dataPos = *(int*)&(header[0x0A]);
    imageSize = *(int*)&(header[0x22]);
    width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize == 0) imageSize = width * height * 3; // 3 bits : Red - 1bit, Green - 1bit, Blue - 1bit
    if (dataPos == 0) dataPos = 54; // The BMP header

    // buffer
    data = new unsigned char[imageSize];

    // Read the actual data from the file into the buffer
    fread(data, 1, imageSize, file);

    fclose(file);

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Binding the newly created texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Give the image to OpenGL
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

    delete[] data;

    Textures* textures = Textures::getTextures();
    textures->data.push_back({ textureID, fileName });

    if (MODEL_DEBUG) {
        std::cout << "Model:loaded - " << folderPath + fileName << '\n';
        std::cout << " - textureID:" << textureID << '\n';
    }
    return textureID;
}

void Model::render()
{
    if (!isInit) return;
    for (const Face& face : fs) {

        Vec3 vertex1 = vs.at(face.v.x1 - 1) * scale;
        Vec3 vertex2 = vs.at(face.v.x2 - 1) * scale;
        Vec3 vertex3 = vs.at(face.v.x3 - 1) * scale;
        vertex1 = vertex1 + pos;
        vertex2 = vertex2 + pos;
        vertex3 = vertex3 + pos;

        Vec2 vertexT1 = vts.at(face.vt.x1 - 1);
        Vec2 vertexT2 = vts.at(face.vt.x2 - 1);
        Vec2 vertexT3 = vts.at(face.vt.x3 - 1);

        glBindTexture(GL_TEXTURE_2D, materials.at(face.material)->texture);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
        
        glTexCoord2d(vertexT1.x, vertexT1.y); glVertex3f(vertex1.x, vertex1.y, vertex1.z);
        glTexCoord2d(vertexT2.x, vertexT1.y); glVertex3f(vertex2.x, vertex2.y, vertex2.z);
        glTexCoord2d(vertexT3.x, vertexT1.y); glVertex3f(vertex3.x, vertex3.y, vertex3.z);
        
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
}