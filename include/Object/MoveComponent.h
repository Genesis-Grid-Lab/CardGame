#pragma once
#include "Object/Component.h"

class MoveComponent : public Component
{
 public:
  // lower update order to update first
  MoveComponent(class Object* owner, int updateOrder = 10)
    :Component(owner, updateOrder),mAngularSpeed(0.0f),mForwardSpeed(0.0f)
  {
  }

  void Update(float deltaTime) override
  {
    if (!Math::NearZero(mAngularSpeed))
      {
	float rot = mOwner->GetRotation();
	rot += mAngularSpeed * deltaTime;
	mOwner->SetRotation(rot);
      }
    
    if (!Math::NearZero(mForwardSpeed))
      {
	Vector2 pos = mOwner->GetPosition();
	pos += mOwner->GetForward() * mForwardSpeed * deltaTime;
	
	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f) { pos.x = 1280.0f; }
	else if (pos.x > 1280.0f) { pos.x = 2.0f; }
	
	if (pos.y < 0.0f) { pos.y = 768.0f; }
	else if (pos.y > 768.0f) { pos.y = 2.0f; }
	
	mOwner->SetPosition(pos);
      }
  }

  float GetAngularSpeed() const { return mAngularSpeed;}
  float GetForwardSpeed() const { return mForwardSpeed;}
  void SetAngularSpeed(float speed) { mAngularSpeed = speed;}
  void SetForwardSpeed(float speed) { mForwardSpeed = speed;}
 private:
  // control rotation (radians/second)
  float mAngularSpeed;
  // control forward movement (units/second)
  float mForwardSpeed;
};
