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
    SDL_Rect r;
    // scale thhe width/height by owner's scale
    r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
    r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
    // cebter the rectangle around the position of the owner
    r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2);
    r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

    // Draw (have to convert angle from radians to degrees, and clockwise to counter)
    SDL_RenderCopyEx(renderer,
		     mTexture,
		     nullptr,
		     &r,
		     -Math::ToDegrees(mOwner->GetRotation()),
		     nullptr,
		     SDL_FLIP_NONE);
  }
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
  mTexture = texture;
  // Set width/height
  SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}