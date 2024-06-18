#pragma once
#include "Core/Config.h"

class Object
{
public:
  enum State{
    EActive,
    EPaused,
    EDead
  };

  Object(class AppInterface* app);
  virtual ~Object();

  void Update(float deltaTime);
  void UpdateComponents(float deltaTime);
  virtual void UpdateObject(float deltaTime);

  void ProcessInput(const uint8_t* keyState);
  virtual void ObjectInput(const uint8_t* keyState);

  // getters/setters
  const Vector2& GetPosition() const { return mPosition;}
  void SetPosition(const Vector2& pos) { mPosition = pos;}
  float GetScale() const { return mScale;}
  void SetScale(float scale) { mScale = scale;}
  float GetRotation() const { return mRotation;}
  void SetRotation(float rotation) { mRotation = rotation;}

  Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation));}
  void AddComponent(class Component* component);
  void RemoveComponent(class Component* component);

  State GetState() const { return mState;}
  void SetState(State state) {mState = state;}

  class AppInterface* GetApp() { return AppIn;}
private:
  State mState;
  Vector2 mPosition;
  float mScale;
  float mRotation;
  std::vector<class Component*> mComponents;
  class AppInterface* AppIn;
};
