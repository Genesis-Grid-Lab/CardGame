#pragma once
#include "Application/AppInterface.h"

class Application : public AppInterface
{
public:
  Application(){
    mIsRunning = true;
    LoadData();
  }
  ~Application(){
    UnloadData();
  }

  void Run(){
    while(mIsRunning){
      AppInterface::OnProcessInput();
      OnProcessInput();
      AppInterface::OnUpdate();
      OnUpdate();
      GenerateOutput();
    }
  }

private:
  virtual void OnProcessInput() override;
  virtual void OnUpdate() override;
  //virtual void GenerateOutput() override;
  void LoadData();
  void MouseUp();
  void MouseDown();
  void MouseMotion();
  void Confirmation();
  class PlayerHand* Hand;
  class Table* mTable;
  class Deck* mDeck;
  class BackGround* bg;
  class Confirmation* confirm;
  bool leftMouseButtonDown = false;
  SDL_Rect* selectedRect = NULL;
  SDL_Point clickOffset;
  int objCount = 0;
  Vector2 startPos;
  int HandPos = 340;
  int TablePos = 340;
};
