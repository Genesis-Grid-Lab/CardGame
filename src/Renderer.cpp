#include "Graphics/Renderer.h"
#include "Window/Window.h"

GraphicsRenderer::GraphicsRenderer(int32_t width, int32_t height, GLFWwindow* window)
    :m_Window(window),Width(width), Height(height)
{
    // Init opengl
    if(glewInit() != GLEW_OK)
    {
	FATAL("failed to init glew!");
	exit(EXIT_FAILURE);
    }

    glewExperimental = GL_TRUE;

    
}

void GraphicsRenderer::LoadSprite(Sprite* sprite)
{
    m_Sprites.push_back(sprite);
}

void GraphicsRenderer::LoadBackGround(BackGround* background)
{
  m_Background = background;
}


void GraphicsRenderer::Draw()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //for(auto bg : m_Background)
    {
        //bg->Draw();
    }
    //m_Background->Draw();
    for(auto sprite : m_Sprites)
    {
	    sprite->Draw();
    }
	//sprite->Draw();
    glfwSwapBuffers(m_Window);
}
