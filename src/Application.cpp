#include "Application/Application.h"

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
}

void Application::StartScene()
{
    
}
