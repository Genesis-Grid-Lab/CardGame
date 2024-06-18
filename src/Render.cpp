#include "Graphics/Render.h"

Render::Render(SDL_Window* window)
  :mWindow(window)
{
  if(!Init()){
    SDL_Log("Failed to init Render");
  }
}

Render::~Render(){
  SDL_DestroyRenderer(mRenderer);
}

bool Render::Init(){
  mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  IMG_Init(IMG_INIT_PNG);
  return true;
}

void Render::Draw(){
  SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
  SDL_RenderClear(mRenderer);
  for (auto sprite : mSprites){
    sprite->Draw(mRenderer);
  }
  SDL_RenderPresent(mRenderer);
}
