#pragma once
#include "Core/Config.h"

class Window
{
public:
  Window(const char* title, int x, int y, int Width, int Height);
  ~Window();

  bool Init();

  SDL_Window* GetSDLWindow(){
    return mWindow;
  }

private:
  const char* mTitle;
  int X,Y,mWidth,mHeight;
  //The window we'll be rendering to
  SDL_Window* mWindow = NULL;
  //the surface contained by the window
  SDL_Surface* mScreenSurface = NULL;
};
