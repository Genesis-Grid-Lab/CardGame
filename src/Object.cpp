#include "Object/Object.h"
#include "Application/AppInterface.h"
#include "Component/Component.h"

Object::Object(AppInterface* app)
  :mState(EActive), mPosition(Vector2::Zero), mScale(1.0f),mRotation(0.0f), AppIn(app)
{
  AppIn->render->AddObject(this);
}

Object::~Object()
{
  AppIn->render->RemoveObject(this);
  while(!mComponents.empty()){
    delete mComponents.back();
  }
}

void Object::Update(float deltaTime)
{
  if(mState == EActive){
    UpdateComponents(deltaTime);
    UpdateObject(deltaTime);
  }
}

void Object::UpdateComponents(float deltaTime)
{
  for (auto comp : mComponents){
    comp->Update(deltaTime);
  }
}

void Object::UpdateObject(float deltaTime)
{
}

void Object::ProcessInput(const uint8_t* keyState)
{
  if(mState == EActive){
    // first process input for components
    for(auto comp : mComponents){
      comp->ProcessInput(keyState);
    }

    ObjectInput(keyState);
  }
}

void Object::ObjectInput(const uint8_t* keyState)
{
}

void Object::AddComponent(Component* component)
{
  // Find the insertion point in the sorted vector
  // (The first element with a order higher than me)
  int myOrder = component->GetUpdateOrder();
  auto iter = mComponents.begin();
  for (;
       iter != mComponents.end();
       ++iter)
    {
      if (myOrder < (*iter)->GetUpdateOrder())
	{
	  break;
	}
    }
  
  // Inserts element before position of iterator
  mComponents.insert(iter, component);
}

void Object::RemoveComponent(Component* component)
{
  auto iter = std::find(mComponents.begin(), mComponents.end(), component);
  if (iter != mComponents.end())
    {
      mComponents.erase(iter);
    }
}
