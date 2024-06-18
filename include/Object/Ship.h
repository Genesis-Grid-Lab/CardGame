#pragma once
#include "Object/Object.h"
#include "Object/InputComponent.h"
#include "Application/AppInterface.h"

class Ship : public Object
{
 public:
  Ship(AppInterface* app)
    :Object(app)
    {
      SpriteComponent* sc = new SpriteComponent(this, 150);
      sc->SetTexture(app->render->GetTexture("Assets/Ship.png"));

      InputComponent* ic = new InputComponent(this);
      ic->SetForwardKey(SDL_SCANCODE_W);
      ic->SetBackKey(SDL_SCANCODE_S);
      ic->SetCounterClockwiseKey(SDL_SCANCODE_D);
      ic->SetClockwiseKey(SDL_SCANCODE_A);
      ic->SetMaxForwardSpeed(300.0f);
      ic->SetMaxAngularSpeed(Math::TwoPi);
      
    }

  void UpdateObject(float deltaTime) override
  {
  }
  void ObjectInput(const uint8_t* keyState) override
  {
  }
 private:
};