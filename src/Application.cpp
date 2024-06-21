#include "Application/Application.h"
#include "Object/Deck.h"
#include "Object/Background.h"
#include "Object/PlayerHand.h"
#include "Object/Table.h"

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
	      if(object->IsSelected)
		{
		  for (auto &drop : render->mObjects)
		    {
		      if(drop->mDComponent != nullptr)
			{
			  if(drop->id == "Table")
			    {
            if(SDL_PointInRect(&mousePos, &drop->mRect))
            {
              //TablePos += 115;
              switch(mTable->mCount)
              {
                case 0:
                  object->SetPosition(Vector2(mTable->Place1.x, mTable->Place1.y));
                  mTable->mCount += 1;
                  break;
                case 1:
                  object->SetPosition(Vector2(mTable->Place2.x, mTable->Place2.y));
                  mTable->mCount += 1;
                  break;
                case 2:
                  object->SetPosition(Vector2(mTable->Place3.x, mTable->Place3.y));
                  mTable->mCount += 1;
                  break;
                case 3:
                  object->SetPosition(Vector2(mTable->Place4.x, mTable->Place4.y));
                  mTable->mCount += 1;
                  break;
                case 4:
                  object->SetPosition(Vector2(mTable->Place5.x, mTable->Place5.y));
                  mTable->mCount += 1;
                  break;
                case 5:
                  object->SetPosition(Vector2(mTable->Place6.x, mTable->Place6.y));
                  mTable->mCount += 1;
                  break;
                case 6:
                  object->SetPosition(Vector2(mTable->Place7.x, mTable->Place7.y));
                  mTable->mCount += 1;
                  break;
                case 7:
                  object->SetPosition(Vector2(mTable->Place8.x, mTable->Place8.y));
                  mTable->mCount += 1;
                  break;
              }
            }            
			      SDL_Log("movePos2: %d", TablePos);
			    }
          else if(drop->id == "Hand")
          {
            if(SDL_PointInRect(&mousePos, &drop->mRect))
            {
              //HandPos += 115;
              switch(Hand->mCount)
              {
                case 0:
                  object->SetPosition(Vector2(Hand->Place1.x, Hand->Place1.y));
                  Hand->mCount += 1;
                  break;
                case 1:
                  object->SetPosition(Vector2(Hand->Place2.x, Hand->Place2.y));
                  Hand->mCount += 1;
                  break;
                case 2:
                  object->SetPosition(Vector2(Hand->Place3.x, Hand->Place3.y));
                  Hand->mCount += 1;
                  break;
                case 3:
                  object->SetPosition(Vector2(Hand->Place4.x, Hand->Place4.y));
                  Hand->mCount += 1;
                  break;
              }
            }
            else
            {
              object->SetPosition(startPos);
            }
            SDL_Log("movePos2: %d", HandPos);
          }
			    else
			    {
			      object->SetPosition(startPos);
			    }
			}
		    }
		}
	      object->IsSelected = false;
	      SDL_Log("up selected: %d", object->IsSelected);	      
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
			SDL_Log("down selected: %s\n selected?: %d", object->id.c_str(), object->IsSelected);
		  
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