#include "Component/DropComponent.h"
#include "Object/Object.h"
#include "Application/AppInterface.h"

DropComponent::DropComponent(Object* owner, int drawOrder)
    :Component(owner), mDrawOrder(drawOrder)
    {
        mOwner->id = "Drop";
    }

DropComponent::~DropComponent()
{

}

void DropComponent::Draw(SDL_Renderer* renderer)
{
    //mRect = new SDL_Rect();
    // scale thhe width/height by owner's scale
    mOwner->mRect.w = 480;
    mOwner->mRect.h = 144;
    // cebter the rectangle around the position of the owner
    mOwner->mRect.x = static_cast<int>(mOwner->GetPosition().x - mOwner->mRect.w / 2);
    mOwner->mRect.y = static_cast<int>(mOwner->GetPosition().y - mOwner->mRect.h / 2);
    
    SDL_SetRenderDrawColor(renderer, 100,0, 255, 255);
    SDL_RenderFillRect(renderer, &mOwner->mRect);
    
}
