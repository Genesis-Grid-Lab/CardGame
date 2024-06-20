#include "Application/Application.h"
#include "Object/Card.h"
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
  
  mCard1 = new Card(this, "Club_1", "Assets/CardAsset/Standard/solitaire/individuals/club/1_club.png");
  mCard2 = new Card(this, "Heart_7", "Assets/CardAsset/Standard/solitaire/individuals/heart/7_heart.png");
  drop->SetPosition(Vector2(640,720-72));
  mCard1->SetPosition(Vector2(512.0f, 384.0f));
  //mShip->SetRotation(Math::PiOver2);
  mCard2->SetPosition(Vector2(100.0f, 384.0f));
   
}
