#pragma once
#include "Object.h"
#include "Application/AppInterface.h"
#include "Component/DropComponent.h"

class PlayerHand : public Object
{
public:
    PlayerHand(AppInterface* app)
        :Object(app)
        {
            mApp = app;
            mDComponent = new DropComponent(this);
           SetPosition(Vector2(APP_WIDTH / 2,APP_HEIGHT-72));
           id = "Hand";
           Place1.x = 480;
           Place1.y = GetPosition().y;
           Place2.x = 585;
           Place2.y = GetPosition().y;
           Place3.x = 690;
           Place3.y = GetPosition().y;
           Place4.x = 795;
           Place4.y = GetPosition().y;
           Places.emplace_back(Place1);
           Places.emplace_back(Place2);
           Places.emplace_back(Place3);
           Places.emplace_back(Place4);
        }

        void UpdateObject(float deltaTime) override
        {
            
        }

        void ObjectInput(const uint8_t* keyState) override
        {

        }

    std::vector<SDL_Rect> Places;
    SDL_Rect Place1, Place2, Place3, Place4;
    AppInterface* mApp;
    int mCount = 0;
};