#pragma once
#include "Object.h"
#include "Application/Application.h"

class Confirmation : public Object
{
public:
    Confirmation(AppInterface* app)
        :Object(app)
    {
        mApp = app;
        id = "Confimation";
    }

    void UpdateObject(float deltaTime) override
    {

    }


    void ObjectInput(const uint8_t* keyState) override
    {

    }

    void ObjDraw() override
    {
        mRect.x = 100;
        mRect.y = 100;
        mRect.w = 300;
        mRect.h = 300;
        SDL_SetRenderDrawColor(mApp->render->GetRenderer(), 255, 100, 255, 255);
        SDL_RenderFillRect(mApp->render->GetRenderer(), &mRect);
    }

    SDL_Rect mRect;
    AppInterface* mApp;
};