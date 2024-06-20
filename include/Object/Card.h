#pragma once
#include "Object/Object.h"
#include "Application/AppInterface.h"

class Card : public Object
{
 public:
 Card(AppInterface* app,std::string name ,std::string texName)
    :Object(app)
    {
      mSComponent = new SpriteComponent(this, 100);
      mSComponent->SetTexture(app->render->GetTexture(texName.c_str()));
      id = name;
      Selectable = true;
    }

  void UpdateObject(float deltaTime) override
  {
  }

  void ObjectInput(const uint8_t* keyState) override
  {
  }
};
