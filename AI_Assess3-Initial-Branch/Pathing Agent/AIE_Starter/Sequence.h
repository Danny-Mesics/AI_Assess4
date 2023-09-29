#pragma once
#include "Composite.h"

namespace AIForGames {
    class Sequence :
        public Composite
    {
    protected:
        virtual ~Sequence();

        virtual void OnInitialize();

        virtual BehaviourResult Update(Agent* agent, float deltaTime);

        Behaviours::iterator m_current;
    };
}

