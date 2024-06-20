#include "Component/Component.h"
#include "Object/Object.h"

Component::Component(Object* owner, int updateOrder)
  :mOwner(owner),mUpdateOrder(updateOrder)
{
  mOwner->AddComponent(this);
}

Component::~Component()
{
  mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
