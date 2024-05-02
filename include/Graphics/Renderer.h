#pragma once
#include "Core/Core.h"
#include "Graphics/Sprite.h"

class GraphicsRenderer
{
public:
    GraphicsRenderer(int32_t width, int32_t height, GLFWwindow* window);

    void Draw();

    void LoadSprite(Sprite* sprite);

private:
    GLFWwindow* m_Window;
    Sprite *sprite;
    std::vector<Sprite*> m_Sprites;
    int32_t Width, Height;
};
