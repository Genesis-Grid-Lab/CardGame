#pragma once
#include "Object.h"
#include "Card.h"
#include "Application/AppInterface.h"

class Deck : public Object
{
public:
    Deck(AppInterface* app)
        :Object(app)
        {
            mSComponent = new SpriteComponent(this, 105);
            SetPosition(Vector2(100, APP_HEIGHT / 2));
            InitCards(app);
            mSComponent->SetTexture(app->render->GetTexture("Assets/CardAsset/Standard/solitaire/individuals/card_back/card_back.png"));

            for(auto& card : mCards)
            {
                card->SetPosition(GetPosition());
            }
            // Initialize random number generator 
            std::random_device rd; 
            std::mt19937 g(rd()); 
            // Shuffle the vector 
            std::random_shuffle(mCards.begin(), mCards.end());
            std::shuffle(mCards.begin(), mCards.end(), g);

            for (auto& card : mCards)
            {
                //SDL_Log("cards: %s", card->id.c_str());
            }
        }
    
    void InitCards(AppInterface* app)
    {
        mCards.emplace_back(new Card(app, "Club_1", "Assets/CardAsset/Standard/solitaire/individuals/club/1_club.png"));
        mCards.emplace_back(new Card(app, "Club_2", "Assets/CardAsset/Standard/solitaire/individuals/club/2_club.png"));
        mCards.emplace_back(new Card(app, "Club_3", "Assets/CardAsset/Standard/solitaire/individuals/club/3_club.png"));
        mCards.emplace_back(new Card(app, "Club_4", "Assets/CardAsset/Standard/solitaire/individuals/club/4_club.png"));
        mCards.emplace_back(new Card(app, "Club_5", "Assets/CardAsset/Standard/solitaire/individuals/club/5_club.png"));
        mCards.emplace_back(new Card(app, "Club_6", "Assets/CardAsset/Standard/solitaire/individuals/club/6_club.png"));
        mCards.emplace_back(new Card(app, "Club_7", "Assets/CardAsset/Standard/solitaire/individuals/club/7_club.png"));
        mCards.emplace_back(new Card(app, "Club_8", "Assets/CardAsset/Standard/solitaire/individuals/club/8_club.png"));
        mCards.emplace_back(new Card(app, "Club_9", "Assets/CardAsset/Standard/solitaire/individuals/club/9_club.png"));
        mCards.emplace_back(new Card(app, "Club_10", "Assets/CardAsset/Standard/solitaire/individuals/club/10_club.png"));
        mCards.emplace_back(new Card(app, "Heart_7", "Assets/CardAsset/Standard/solitaire/individuals/heart/7_heart.png"));
    }

    void ShuffleCards()
    {
        std::random_device rd; 
        std::mt19937 g(rd()); 
        // Shuffle the vector 
        std::random_shuffle(mCards.begin(), mCards.end());
        std::shuffle(mCards.begin(), mCards.end(), g);

        for (auto& card : mCards)
        {
            //SDL_Log("cards: %s", card->id.c_str());
        }
    }
    
    void UpdateObject(float deltaTime) override
    {

    }

    void ObjectInput(const uint8_t* keyState) override
    {

    }

    std::vector<Card*> mCards;
};