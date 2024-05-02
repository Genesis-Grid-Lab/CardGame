#pragma once
#include "Core/Core.h"
#include "Texture.h"
#include "Shader.h"

class Sprite
{
public:
    Sprite(Shader &shader);
    ~Sprite();

    void Draw(Texture2D &texture, glm::vec2 position,
	      glm::vec2 size = glm::vec2(10.0f, 10.0f),
	      float rotate = 0.0f,
	      glm::vec3 color = glm::vec3(1.0f));
private:
    Shader m_Shader;
    unsigned int quadVAO;

    void initRenderData();
};
