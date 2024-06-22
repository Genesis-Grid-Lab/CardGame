#pragma once
#include "CardMath.h"
#include "Object.h"
#include "Application/AppInterface.h"
#include "Component/DropComponent.h"
#include "Place.h"

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
    Place1 = new Place(app);
    Place1->SetPosition(Vector2(480 , GetPosition().y ));
    
    Place2 = new Place(app);
    Place2->SetPosition(Vector2(585 , GetPosition().y ));
    
    Place3 = new Place(app);
    Place3->SetPosition(Vector2(690 , GetPosition().y ));    
    
    Place4 = new Place(app);
    Place4->SetPosition(Vector2(795, GetPosition().y));    
    
    //Places.emplace_back(Place1);
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
  void ObjDraw() override
  {
    
  }

  std::vector<Place*> Places;
  Place* Place1; 
  Place* Place2; 
  Place* Place3; 
  Place* Place4;
  AppInterface* mApp;
  int mCount = 0;
};
