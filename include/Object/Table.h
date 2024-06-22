#pragma once
#include "CardMath.h"
#include "Object.h"
#include "Application/AppInterface.h"
#include "Component/DropComponent.h"
#include "Place.h"

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

            Place1 = new Place(app);
            Place1->SetPosition(Vector2(480, GetPosition().y - 72));
        

            Place2 = new Place(app);
            Place2->SetPosition(Vector2(585 , GetPosition().y - 72));            
            
            Place3 = new Place(app);
            Place3->SetPosition(Vector2(690 , GetPosition().y - 72));
           
           Place4 = new Place(app);
           Place4->SetPosition(Vector2(795, GetPosition().y - 72));           
           
           Place5 = new Place(app);
           Place5->SetPosition(Vector2(480 , GetPosition().y + 149  - 72));           
           
            Place6 = new Place(app);
            Place6->SetPosition(Vector2(585, GetPosition().y + 149 - 72));           
           
            Place7 = new Place(app);
            Place7->SetPosition(Vector2(690 , GetPosition().y + 149 - 72));           
           
            Place8 = new Place(app);
            Place8->SetPosition(Vector2(795 , GetPosition().y + 149 - 72));           
           
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

   void ObjDraw() override
  {
    
  }

    std::vector<Place*> Places;
    Place* Place1;
    Place* Place2;
    Place* Place3; 
    Place* Place4;
    Place* Place5;
    Place* Place6;
    Place* Place7;
    Place* Place8;
    AppInterface* mApp;
    int mCount = 0;
};
