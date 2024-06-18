#include "Application/Application.h"
#include "Object/Ship.h"

void Application::OnProcessInput(){
  
}

void Application::OnUpdate(){
  
}

void Application::LoadData(){
  mShip = new Ship(this);
  mShip->SetPosition(Vector2(512.0f, 384.0f));
  mShip->SetRotation(Math::PiOver2);
}
