#pragma once
#include "Object/MoveComponent.h"
#include "Object/Object.h"

class InputComponent : public MoveComponent
{
 public:
  // lower update order to update first
  InputComponent(Object* owner)
    :MoveComponent(owner),mForwardKey(0),mBackKey(0),mClockwiseKey(0),mCounterClockwiseKey(0)
  {
  }

  void ProcessInput(const uint8_t* keyState) override
  {
    // Calculate forward speed for MoveComponent
    float forwardSpeed = 0.0f;
    if (keyState[mForwardKey])
      {
	forwardSpeed += mMaxForwardSpeed;
      }
    if (keyState[mBackKey])
      {
	forwardSpeed -= mMaxForwardSpeed;
      }
    SetForwardSpeed(forwardSpeed);
    
    // Calculate angular speed for MoveComponent
    float angularSpeed = 0.0f;
    if (keyState[mClockwiseKey])
      {
	angularSpeed += mMaxAngularSpeed;
      }
    if (keyState[mCounterClockwiseKey])
      {
	angularSpeed -= mMaxAngularSpeed;
      }
    SetAngularSpeed(angularSpeed);
  }

  // getter/setters
  float GetMaxForward() const { return mMaxForwardSpeed; }
  float GetMaxAngular() const { return mMaxAngularSpeed; }
  int GetForwardKey() const { return mForwardKey; }
  int GetBackKey() const { return mBackKey; }
  int GetClockwiseKey() const { return mClockwiseKey; }
  int GetCounterClockwiseKey() const { return mCounterClockwiseKey; }

  void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
  void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
  void SetForwardKey(int key) { mForwardKey = key; }
  void SetBackKey(int key) { mBackKey = key; }
  void SetClockwiseKey(int key) { mClockwiseKey = key; }
  void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }
private:
  // The maximum forward/angular speeds
  float mMaxForwardSpeed;
  float mMaxAngularSpeed;
  // Keys for forward/back movement
  int mForwardKey;
  int mBackKey;
  // Keys for angular movement
  int mClockwiseKey;
  int mCounterClockwiseKey;
};
