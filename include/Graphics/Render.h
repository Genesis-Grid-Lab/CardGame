#pragma once
#include "Core/Config.h"
#include "Object/Object.h"
#include "Component/SpriteComponent.h"
#include "Component/DropComponent.h"

class Render
{
public:
  Render(SDL_Window* window);
  ~Render();

  bool Init();
  void Draw();
  void AddObject(Object* object){
    // if updating object, need to add to pending
    if(mUpdatingObjects){
      mPendingObjects.emplace_back(object);
    }
    else{
      mObjects.emplace_back(object);
    }
  }

  void RemoveObject(Object* object){
    // Is it in pending object?
    auto iter = std::find(mPendingObjects.begin(), mPendingObjects.end(),object);
    if(iter != mPendingObjects.end()){
      //swap to end of vector and pop off
      std::iter_swap(iter, mPendingObjects.end() - 1);
      mPendingObjects.pop_back();
    }

    //Is is in onjects?
    iter = std::find(mObjects.begin(), mObjects.end(), object);
    if(iter != mObjects.end()){
      //swap to end of vector and pop off
      std::iter_swap(iter, mObjects.end() - 1);
      mObjects.pop_back();
    }
  }

  void AddSprite(SpriteComponent* sprite){
    // Find the insertion point in the sorted vector
    // (The first element with a higher draw order than me)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for ( ;
	  iter != mSprites.end();
	  ++iter)
      {
	if (myDrawOrder < (*iter)->GetDrawOrder())
	  {
	    break;
	  }
      }
    
    // Inserts element before position of iterator
    mSprites.insert(iter, sprite);
  }

  void RemoveSprite( SpriteComponent* sprite){
    // (We can't swap because it ruins ordering)
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
  }

  SDL_Texture* GetTexture(const std::string& fileName){
    SDL_Texture* tex = nullptr;
    // Is the texture already in the map?
    auto iter = mTextures.find(fileName);
    if (iter != mTextures.end())
      {
	tex = iter->second;
      }
    else
      {
	// Load from file
	SDL_Surface* surf = IMG_Load(fileName.c_str());
	if (!surf)
	  {
	    SDL_Log("Failed to load texture file %s", fileName.c_str());
	    return nullptr;
	  }
	
	// Create texture from surface
	tex = SDL_CreateTextureFromSurface(mRenderer, surf);
	SDL_FreeSurface(surf);
	if (!tex)
	  {
	    SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
	    return nullptr;
	  }
	
	mTextures.emplace(fileName.c_str(), tex);
      }
    return tex;
  }
private:
  SDL_Window* mWindow;
  SDL_Renderer* mRenderer;
 public:
  std::unordered_map<std::string, SDL_Texture*> mTextures;
  std::vector<Object*> mObjects;
  std::vector<Object*> mPendingObjects;
  std::vector<SpriteComponent*> mSprites;
  bool mUpdatingObjects;
};
