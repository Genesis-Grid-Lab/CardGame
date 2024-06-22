#include "Application/Application.h"
#include "CardMath.h"
#include "Object/Deck.h"
#include "Object/Background.h"
#include "Object/PlayerHand.h"
#include "Object/Table.h"
#include "Object/Confirmation.h"

void Application::OnProcessInput(){
  while(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	mIsRunning = false;
	break;
      case SDL_MOUSEMOTION:
      MouseMotion();
	break;
      case SDL_MOUSEBUTTONUP:
      MouseUp();
	break;
      case SDL_MOUSEBUTTONDOWN:
      MouseDown();
	break;
      }
      
    }

}

void Application::OnUpdate(){
  //  SDL_Log("sletec: %d", mShip->IsSelected);
}

void Application::LoadData(){
  bg = new BackGround(this);
  Hand = new PlayerHand(this);
  mTable = new Table(this);
  mDeck = new Deck(this);
  
  mDeck->ShuffleCards();
  SDL_Log("debug");
  for(auto &card : render->mObjects)
  {
	SDL_Log("card: %s fin2", card->id.c_str());
  }

  	std::random_device rd; 
	std::mt19937 g(rd()); 
	// Shuffle the vector 
	std::random_shuffle(render->mObjects.begin(), render->mObjects.end());
	std::shuffle(render->mObjects.begin(), render->mObjects.end(), g);
	for(auto &card : render->mObjects)
  {
	SDL_Log("card: %s fin1", card->id.c_str());
  }
  
  //mCard1->SetPosition(Vector2(512.0f, 384.0f));
  //mShip->SetRotation(Math::PiOver2);
  //mCard2->SetPosition(Vector2(100.0f, 384.0f));
   
}

void Application::MouseUp()
{
  if(leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
	  {
	    leftMouseButtonDown = false;
	    selectedRect = NULL;
	    objCount = 0;	    
	    for (auto &object : render->mObjects){
		//SDL_Log("cards: %d", object->id.c_str());
			for(auto &drop : render->mObjects){
				if(object->IsSelected)
				{
					//if(drop->mDComponent != NULL){
						SDL_Log("in rect");
						for (auto &tablePlace : mTable->Places)
							{
							
							for(auto &handPlace : Hand->Places)
								{
									if(object->checkCollision(handPlace->mRect) && objCount == 0)
									{			  
										objCount = 1;
										object->SetPosition(Vector2(handPlace->GetPosition().x, handPlace->GetPosition().y));
									//object->Select
									}
									objCount = 0;

									if(object->checkCollision(tablePlace->mRect) && objCount == 0)
									{
										objCount = 1;
										object->SetPosition(Vector2(tablePlace->GetPosition().x, tablePlace->GetPosition().y));
										//object->Selectable = false;
										SDL_Log("tablex: %d\n tabley: %d", tablePlace->mRect.x, tablePlace->mRect.y);
										//Confirmation();
									}
									objCount = 0;

									if(!object->checkCollision(tablePlace->mRect) && !object->checkCollision(handPlace->mRect) && objCount == 0)
									{
										//object->SetPosition(startPos);
										//SDL_Log("no collision");
									}									
									
								}
									
							}

					//}					
				
				}
			}
			    
	      object->IsSelected = false;
	      //SDL_Log("up selected: %d", object->IsSelected);
	    }
	  }
}


void Application::MouseDown()
{
  if(!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT)
	  {
	    leftMouseButtonDown = true;	    
	      for (auto &object : render->mObjects){
		      if(SDL_PointInRect(&mousePos, &object->mRect) && object->Selectable){
			if(objCount == 0){
		          object->IsSelected = true;
			  objCount = 1;
			}
			selectedRect = &object->mRect;
			clickOffset.x = mousePos.x - object->mRect.x;
			clickOffset.y = mousePos.y - object->mRect.y;
			startPos = object->GetPosition();
			//SDL_Log("down selected: %s\n selected?: %d", object->id.c_str(), object->IsSelected);
		  
		      }
		     
	      }
	      //SDL_Log("mouse down clickoffsetx: %s", clickOffset.x);
	  }
}

void Application::MouseMotion()
{
  mousePos = {event.motion.x, event.motion.y};
	if(leftMouseButtonDown && selectedRect != NULL){
	  selectedRect->x = mousePos.x - clickOffset.x;
	  selectedRect->y = mousePos.y - clickOffset.y;
	  Vector2 pos = Vector2(mousePos.x, mousePos.y);
	  //SDL_Log("x: %d", selectedRect->x);
	  for (auto &object : render->mObjects){
	    if(object->Selectable && object->IsSelected){
	      object->SetPosition(pos);
	      //SDL_Log("selectd: %d", object->IsSelected);
	    }
	  }
	}
}

void Application::Confirmation()
{
	confirm = new class Confirmation(this);
}
