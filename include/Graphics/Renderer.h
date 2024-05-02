#pragma once
#include "Core/Core.h"

class GraphicsRenderer
{
public:
    GraphicsRenderer(int32_t width, int32_t height, GLFWwindow* window);

    void Draw();

private:
    GLFWwindow* m_Window;
};
