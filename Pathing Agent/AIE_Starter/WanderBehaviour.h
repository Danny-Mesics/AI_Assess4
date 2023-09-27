#pragma once
#include "Behaviour.h"
namespace AIForGames
{
    class WanderBehaviour :
        public Behaviour
    {
    public:
        virtual void Enter(Agent* agent);
        virtual void Update(Agent* agent, float deltaTime);
    };
}

