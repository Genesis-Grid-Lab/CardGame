#include "Window/Window.h"

Window::Window(const char* title, int x, int y, int Width, int Height)
  :mTitle(title),X(x),Y(y),mWidth(Width),mHeight(Height)
{
  if(!Init()) {
    SDL_Log("Failed to init Window");
  }
}

bool Window::Init() {

  // Init SDL
  int sdlResult = SDL_Init(SDL_INIT_VIDEO);
  if(sdlResult != 0) {
    SDL_Log("Unable to iniy SDL: %s", SDL_GetError());
    return false;
  }

  mWindow = SDL_CreateWindow(mTitle, X, Y, mWidth, mHeight, 0);

  if(!mWindow){
    SDL_Log("Failed to create sdl window: %s", SDL_GetError());
    return false;
  }
  return true;
}

Window::~Window(){
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}
