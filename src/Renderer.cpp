#include "Graphics/Renderer.h"
#include "Window/Window.h"
#include "Core/ResourceManager.h"

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


    ResourceManager::LoadShader("Assets/Shaders/vertex.shader", "Assets/Shaders/fragment.shader", nullptr, "Sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
				      static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("Sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("Sprite").SetMatrix4("projection", projection);
    ResourceManager::LoadTexture("Assets/images/awesomeface.png", true, "face");
    sprite = new Sprite(ResourceManager::GetShader("Sprite"), ResourceManager::GetTexture("face"));
    LoadSprite(sprite);
    sprite->Position = glm::vec2(200.0f, 200.0f);
    sprite->Size = glm::vec2(300.0f, 400.0f);
    sprite->Rotate = 45.0f;
    sprite->Color = glm::vec3(0.0f, 1.0f, 0.0f);

    
}

void GraphicsRenderer::LoadSprite(Sprite* sprite)
{
    m_Sprites.push_back(sprite);
}

void GraphicsRenderer::Draw()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto sprite : m_Sprites)
    {
	sprite->Draw();
    }
	//sprite->Draw();
    glfwSwapBuffers(m_Window);
}
