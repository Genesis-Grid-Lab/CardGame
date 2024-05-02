#pragma once
#include "Window/Window.h"
#include "Graphics/Renderer.h"

// forward declaration
class AppInterface;

// application context
class AppContext
{
public:
    inline AppContext()
    {
	Window = std::make_unique<AppWindow>(&Dispatcher, 1280, 720, "CardGame");
	Renderer = std::make_unique<GraphicsRenderer>(1280, 720, Window->Handle());
	DeltaTime = 0.0;
    }

    inline ~AppContext()
    {
	for (auto layer : Layers)
	{
	    DELETE(layer);
	}
    }

    std::unique_ptr<AppWindow> Window;
    std::unique_ptr<GraphicsRenderer> Renderer;
    std::vector<AppInterface*> Layers;
    EventDispatcher Dispatcher;
    double DeltaTime;
};
