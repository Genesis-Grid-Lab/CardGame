#pragma once
#include "AppInterface.h"

class Application : public AppInterface
{
public:
    // create application context
    inline Application()
    {
	// create application context
	m_LayerID = TypeID<Application>();
	m_Context = new AppContext();

	// register callbacks
	RegisterCallbacks();

	//start scene
	StartScene();
    }
    
    // runs application main loop
    void RunContext(bool showFrame)
    {
	// application main loop
	while(m_Context->Window->PollEvents())
	{
	    // set delta time
	    UpdateDeltaTime();

	    // update scene
	    UpdateScene();

	    //render scene
	    RenderScene();

	    for(auto layer : m_Context->Layers)
	    {
		layer->OnUpdate();
	    }

	    // show only for game
	    
	}
    }
    
    inline ~Application()
    {
	DELETE(m_Context);
    }

private:
    // register event callback funtions
    void RegisterCallbacks();
    // compute frame delta time value
    void UpdateDeltaTime();
    // Update scene
    void UpdateScene();
    // Render scene
    void RenderScene();
    // start scene
    void StartScene();
};
