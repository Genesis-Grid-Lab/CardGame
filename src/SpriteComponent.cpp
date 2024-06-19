#include "Object/SpriteComponent.h"
#include "Object/Object.h"
#include "Application/AppInterface.h"

SpriteComponent::SpriteComponent(Object* owner, int drawOrder)
  :Component(owner), mTexture(nullptr), mDrawOrder(drawOrder),mTexWidth(0),mTexHeight(0)
{
  mOwner->GetApp()->render->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
  mOwner->GetApp()->render->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
  if(mTexture){
    //mRect = new SDL_Rect();
    // scale thhe width/height by owner's scale
    mRect.w = static_cast<int>(mTexWidth * mOwner->GetScale());
    mRect.h = static_cast<int>(mTexHeight * mOwner->GetScale());
    // cebter the rectangle around the position of the owner
    mRect.x = static_cast<int>(mOwner->GetPosition().x - mRect.w / 2);
    mRect.y = static_cast<int>(mOwner->GetPosition().y - mRect.h / 2);

    if (mOwner->IsSelected){
    SDL_SetRenderDrawColor(renderer, 0,0, 255, 255);
    SDL_RenderFillRect(renderer, &mRect);
    }
    else{
    // Draw (have to convert angle from radians to degrees, and clockwise to counter)
    SDL_RenderCopyEx(renderer,
		     mTexture,
		     nullptr,
		     &mRect,
		     -Math::ToDegrees(mOwner->GetRotation()),
		     nullptr,
		     SDL_FLIP_NONE);
    }
    
  }
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
  mTexture = texture;
  // Set width/height
  SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
