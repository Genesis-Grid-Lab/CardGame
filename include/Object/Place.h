#pragma once
#include "Object.h"
#include "Application/AppInterface.h"

class Place : public Object
{
public:
    Place(AppInterface* app)
        :Object(app)
        {
            mApp = app;
            mRect.w = CARD_WIDTH;
            mRect.h = CARD_HEIGHT;
            
        }
    void UpdateObject(float deltaTime) override
    {
        
    }

    void ObjectInput(const uint8_t* keyState) override
    {

    }

    void ObjDraw() override
    {
        mRect.x = static_cast<int>(GetPosition().x - mRect.w / 2);
            mRect.y = static_cast<int>(GetPosition().y - mRect.h / 2);
        SDL_SetRenderDrawColor(mApp->render->GetRenderer(), 200, 50, 255, 255);
	    SDL_RenderFillRect(mApp->render->GetRenderer(), &mRect);
    }

    AppInterface* mApp;
};