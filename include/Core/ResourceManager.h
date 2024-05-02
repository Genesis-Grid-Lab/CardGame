#pragma once
#include "Core.h"

#include "Graphics/Texture.h"
#include "Graphics/Shader.h"

class ResourceManager
{
public:
    //Resource storage
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;
    // loads a shader program from file loading vertex, fragm (geometry)
    static Shader &LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
    // retreive a stored shader
    static Shader &GetShader(std::string name);
    // loads a texture from file
    static Texture2D &LoadTexture(const char* file, bool alpha, std::string name);
    // retreive a strored texture
    static Texture2D &GetTexture(std::string name);
    // properly de-allocates all loaded resources
    static void Clear();
private:
    ResourceManager() {}
    // loads and generate a shader from file
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    // loads a single texture from file
    static Texture2D loadTextureFromFile(const char* file, bool alpha);
};
