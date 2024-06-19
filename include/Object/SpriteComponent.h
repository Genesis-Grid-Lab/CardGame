#pragma once
#include "Object/Component.h"

class SpriteComponent : public Component
{
public:
  // lower draw order further back
  SpriteComponent(class Object* owner, int drawOrder = 100);
  ~SpriteComponent();

  virtual void Draw(SDL_Renderer* renderer);
  virtual void SetTexture(SDL_Texture* texture);

  int GetDrawOrder() const { return mDrawOrder;}
  int GetTexHeight() const { return mTexHeight;}
  int GetTexWidth() const { return mTexWidth;}

  SDL_Rect mRect;
 protected:
  SDL_Texture* mTexture;
  int mDrawOrder, mTexHeight, mTexWidth;
};
