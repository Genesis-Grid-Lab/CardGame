#include "Application/Application.h"
#include "Object/Ship.h"
#include "Object/Background.h"
#include "Object/DropTest.h"

void Application::OnProcessInput(){
  
}

void Application::OnUpdate(){
  //  SDL_Log("sletec: %d", mShip->IsSelected);
}

void Application::LoadData(){
  bg = new BackGround(this);
  drop = new DropTest(this);
  
  mShip = new Ship(this);
  ship2 = new Ship(this);
  drop->SetPosition(Vector2(600,720));
  mShip->SetPosition(Vector2(512.0f, 384.0f));
  mShip->SetRotation(Math::PiOver2);
  ship2->SetPosition(Vector2(100.0f, 384.0f));
   
}
