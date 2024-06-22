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
  virtual void ObjDraw() {}
  bool checkCollision(SDL_Rect rect)
  {
    //the sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // calculate the sides of rect A
    leftA = mRect.x;
    rightA = mRect.x + mRect.w;
    topA = mRect.y;
    bottomA = mRect.y + mRect.h;

    // calculate the side of rect B
    leftB = rect.x;
    rightB = rect.x + rect.w;
    topB = rect.y;
    bottomB = rect.y + rect.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
  }
  
  bool IsSelected = false;
private:
  State mState;
  Vector2 mPosition;
  float mScale;
  float mRotation;
  std::vector<class Component*> mComponents;
  class AppInterface* AppIn;
public:
  class SpriteComponent* mSComponent = NULL;
  class DropComponent* mDComponent = NULL;
  std::string id;
  bool Selectable = false;
  SDL_Rect mRect;
};
