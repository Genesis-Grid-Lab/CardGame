#pragma once
#include "Object.h"
#include "Application/AppInterface.h"
#include "Component/DropComponent.h"

class DropTest : public Object
{
public:
    DropTest(AppInterface* app)
        :Object(app)
        {
            mDComponent = new DropComponent(this);
            
        }

        void UpdateObject(float deltaTime) override
        {

        }

        void ObjectInput(const uint8_t* keyState) override
        {

        }
};