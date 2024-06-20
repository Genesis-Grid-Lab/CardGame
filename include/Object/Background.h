#pragma once
#include "Object/Object.h"
#include "Application/AppInterface.h"
#include "Component/SpriteComponent.h"

class BackGround : public Object
{
public:
  BackGround(AppInterface* app)
    :Object(app)
    {
      mSComponent = new SpriteComponent(this, 1);
      mSComponent->SetTexture(app->render->GetTexture("Assets/CardAsset/Backgrounds/background_3.png"));
      SetRotation(Math::PiOver2);
      SetPosition(Vector2(640, 360));
      
    }

  void UpdateObject(float deltaTime) override
  {
  }

  void ObjectInput(const uint8_t* keyState) override
  {
  }
};
