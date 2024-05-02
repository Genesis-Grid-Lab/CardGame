#pragma once
#include "Core/Core.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

class Sprite
{
public:
    Sprite(Shader &shader, Texture2D &texture);
    ~Sprite();

    void Draw();
public:
    glm::vec2 Position;
    glm::vec2 Size;
    float Rotate;
    glm::vec3 Color;
private:
    Texture2D &m_Texture;
    Shader m_Shader;
    unsigned int quadVAO;

    void initRenderData();
};
