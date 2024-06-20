#pragma once
#include "Component.h"

class DropComponent : public Component
{
public:
    DropComponent(class Object* owner, int drawOrder = 10);
    ~DropComponent();

    virtual void Draw(SDL_Renderer* renderer);

    int GetDrawOrder() const { return mDrawOrder;}
private:
    int mDrawOrder;
};