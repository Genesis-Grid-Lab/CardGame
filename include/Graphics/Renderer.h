#pragma once
#include "Core/Core.h"
#include "Graphics/Sprite.h"
#include "Core/ResourceManager.h"

class GraphicsRenderer
{
public:
    GraphicsRenderer(int32_t width, int32_t height, GLFWwindow* window);

    void Draw();

    void LoadSprite(Sprite* sprite);
    inline void LoadShader(const char* vShaderFile, const char* fShaderFile, std::string name)
	{
	    ResourceManager::LoadShader(vShaderFile, fShaderFile, nullptr, name);
	}
    inline void LoadTexture(const char* file, bool alpha, std::string name)
	{
	    ResourceManager::LoadTexture(file, alpha, name);
	}
    

private:
    GLFWwindow* m_Window;
    std::vector<Sprite*> m_Sprites;
public:
    int32_t Width, Height;
};
