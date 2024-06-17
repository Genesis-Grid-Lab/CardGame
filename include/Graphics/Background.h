#pragma once
#include "Core/Core.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

class BackGround
{
public:
  BackGround(Shader &shader, Texture2D &texture, class Application* app);
  ~BackGround();

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
