#pragma once
#include "Core/Config.h"

class Component
{
public:
  //the lower the update ordor the earlier the component updates
  Component(class Object* owner, int updateOrder = 100);
  virtual ~Component();

  virtual void Update(float deltaTime);
  virtual void ProcessInput(const uint8_t* keyState) {}
  int GetUpdateOrder() const { return mUpdateOrder;}
protected:
  class Object* mOwner;
  int mUpdateOrder;
};
