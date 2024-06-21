#pragma once
#include "Object.h"
#include "Application/AppInterface.h"
#include "Component/DropComponent.h"

class Table : public Object
{
public:
    Table(AppInterface* app)
        :Object(app)
        {
            mDComponent = new DropComponent(this);            
            SetPosition(Vector2(APP_WIDTH / 2, APP_HEIGHT / 2));
            id = "Table";
            mRect.h = 288;

            Place1.x = 480;
           Place1.y = GetPosition().y - 72;
           Place2.x = 585;
           Place2.y = GetPosition().y - 72;
           Place3.x = 690;
           Place3.y = GetPosition().y - 72;
           Place4.x = 795;
           Place4.y = GetPosition().y - 72;
           Place5.x = 480;
           Place5.y = GetPosition().y + 149 - 72;
           Place6.x = 585;
           Place6.y = GetPosition().y + 149 - 72;
           Place7.x = 690;
           Place7.y = GetPosition().y + 149 - 72;
           Place8.x = 795;
           Place8.y = GetPosition().y + 149 - 72;
           Places.emplace_back(Place1);
           Places.emplace_back(Place2);
           Places.emplace_back(Place3);
           Places.emplace_back(Place4);
           Places.emplace_back(Place5);
           Places.emplace_back(Place6);
           Places.emplace_back(Place7);
           Places.emplace_back(Place8);
        }

    void UpdateObject(float deltaTime) override
    {

    }

    void ObjectInput(const uint8_t* keyState) override
    {

    }

    std::vector<SDL_Rect> Places;
    SDL_Rect Place1, Place2, Place3, Place4, Place5, Place6, Place7, Place8;
    AppInterface* mApp;
    int mCount = 0;
};