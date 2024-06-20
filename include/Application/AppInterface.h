#pragma once
#include "Window/Window.h"
#include "Graphics/Render.h"
#include "Object/Object.h"
#include "Component/Component.h"

class AppInterface
{
public:
  AppInterface(){
    window = new Window("CardGame", 100, 100, 1280, 768);
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
    while(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	mIsRunning = false;
	break;
      case SDL_MOUSEMOTION:
	mousePos = {event.motion.x, event.motion.y};
	if(leftMouseButtonDown && selectedRect != NULL){
	  selectedRect->x = mousePos.x - clickOffset.x;
	  selectedRect->y = mousePos.y - clickOffset.y;
	  Vector2 pos = Vector2(mousePos.x, mousePos.y);
	  //SDL_Log("x: %d", selectedRect->x);
	  for (auto &object : render->mObjects){
	    if(object->Selectable && object->IsSelected){
	      object->SetPosition(pos);
	      SDL_Log("selectd: %d", object->IsSelected);
	    }
	  }
	}
	break;
      case SDL_MOUSEBUTTONUP:
	if(leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
	  {
	    leftMouseButtonDown = false;
	    selectedRect = NULL;
      objCount = 0;	    
	    for (auto &object : render->mObjects){
        if(object->IsSelected)
        {
          for (auto &drop : render->mObjects)
          {
            if(drop->mDComponent != nullptr)
            {
              if(SDL_PointInRect(&mousePos, &drop->mRect))
              {
                object->SetPosition(drop->GetPosition());    
              }
              else
              {
                object->SetPosition(startPos);
              }
            }
          }
        }
	      object->IsSelected = false;
	      SDL_Log("up selected: %d", object->IsSelected);	      
	    }
	  }
	break;
      case SDL_MOUSEBUTTONDOWN:
	if(!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
	  {
	    leftMouseButtonDown = true;	    
	      for (auto &object : render->mObjects){
		      if(SDL_PointInRect(&mousePos, &object->mRect) && object->Selectable){
            if(objCount == 0){
		          object->IsSelected = true;
              objCount = 1;
            }
		    selectedRect = &object->mRect;
		    clickOffset.x = mousePos.x - object->mRect.x;
		    clickOffset.y = mousePos.y - object->mRect.y;
        startPos = object->GetPosition();
		    SDL_Log("down selected: %s\n selected?: %d", object->id.c_str(), object->IsSelected);
		  
		}
	    }
	    //SDL_Log("mouse down clickoffsetx: %s", clickOffset.x);
	  }
	break;
      }
      
    }

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
  bool leftMouseButtonDown = false;
  SDL_Rect* selectedRect = NULL;
  SDL_Point clickOffset;
  int objCount = 0;
  Vector2 startPos;
};  
