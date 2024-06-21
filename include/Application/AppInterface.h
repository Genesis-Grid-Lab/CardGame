#pragma once
#include "Window/Window.h"
#include "Graphics/Render.h"
#include "Object/Object.h"
#include "Component/Component.h"

class AppInterface
{
public:
  AppInterface(){
    window = new Window("CardGame", 100, 100, APP_WIDTH, APP_HEIGHT);
    render = new Render(window->GetSDLWindow());

    mTicksCount = 0;
    deltaTime = 0.0f;//(SDL_GetTicks() - mTicksCount) / 1000.0f;
    //mTicksCount = SDL_GetTicks();
  }

  virtual void OnUpdate(){
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
      ;

    deltaTime = (SDL_GetTicks() - mTicksCount)/ 1000.0f;

    if(deltaTime > 0.05f){
      deltaTime = 0.05f;
    }

    mTicksCount = SDL_GetTicks();

    // Update all objects
    render->mUpdatingObjects = true;
    for(auto object : render->mObjects){
      object->Update(deltaTime);             
    }

    render->mUpdatingObjects = false;

    // move any pending objects to mObjects
    for(auto pending : render->mPendingObjects){
      render->mObjects.emplace_back(pending);
    }

    render->mPendingObjects.clear();

    // Add any dead actors to a temp vector
    std::vector<Object*> deadObjects;
    for(auto object : render->mObjects){
      if(object->GetState() == Object::EDead){
	      deadObjects.emplace_back(object);
      }
    }

    // delete dead objects
    for(auto object : deadObjects){
      delete object;
    }
  }

  virtual void OnProcessInput(){
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if(state[SDL_SCANCODE_ESCAPE]){
      mIsRunning = false;
    }

    render->mUpdatingObjects = true;
    for (auto object : render->mObjects){
      object->ProcessInput(state);     
    }
    render->mUpdatingObjects = false;
  }

  virtual void GenerateOutput(){
    render->Draw();
  }

  ~AppInterface(){
  }

  virtual void UnloadData(){
    while(!render->mObjects.empty())
      delete render->mObjects.back();
  }

  Window* window;
  Render* render;
  Uint32 mTicksCount;
  float deltaTime;
  bool mIsRunning;
  SDL_Event event;
  SDL_Point mousePos;
private:
  
};  
