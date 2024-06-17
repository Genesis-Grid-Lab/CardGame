#include "Application/Application.h"
#include "Graphics/Sprite.h"



void Application::RegisterCallbacks()
{
    // attach window resize event callback
    // AttachCallback<WindowResizeEvent>([this] (auto e)
    // 	{
    // 	    // resize renderer framebuffer

	    
    // 	})
}

void Application::UpdateDeltaTime()
{
    static double sLastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    m_Context->DeltaTime = (currentTime - sLastTime);
    sLastTime = currentTime;
}

void Application::UpdateScene()
{
    
}

void Application::RenderScene()
{
    m_Context->Renderer->Draw();
    //back->Draw();
    Renderer->DrawSprite(ResourceManager::GetTexture("face"), glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Application::StartScene()
{
    m_Context->Renderer->LoadShader("Assets/Shaders/vertex.shader", "Assets/Shaders/fragment.shader", "Sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_Context->Renderer->Width),
				      static_cast<float>(m_Context->Renderer->Height), 0.0f, -1.0f, 1.0f);
    
    ResourceManager::GetShader("Sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("Sprite").SetMatrix4("projection", projection);
    m_Context->Renderer->LoadTexture("Assets/images/awesomeface.png", true, "face");
    //m_Context->Renderer->LoadTexture("Assets/images/green.png", false, "back");
    Renderer = new SpriteRenderer(ResourceManager::GetShader("Sprite"));

    back = new BackGround(ResourceManager::GetShader("Sprite"), ResourceManager::GetTexture("face"), this);
    //Sprite *sprite = new Sprite(ResourceManager::GetShader("Sprite"), ResourceManager::GetTexture("face"), this);
    //m_Context->Renderer->LoadBackGround(back);
    
    /*sprite->Position = glm::vec2(200.0f, 200.0f);
    sprite->Size = glm::vec2(100.0f, 100.0f);
    sprite->Rotate = 0.0f;
    sprite->Color = glm::vec3(1.0f, 1.0f, 0.0f);*/
}
