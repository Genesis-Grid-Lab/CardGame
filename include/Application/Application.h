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
  class DropTest* drop;
  class Card* mCard2;
  class Card* mCard1;
  class BackGround* bg;
};
