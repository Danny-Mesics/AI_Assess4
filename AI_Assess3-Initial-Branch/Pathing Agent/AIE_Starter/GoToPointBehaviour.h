#pragma once
#include "Behaviour.h"
#include "raylib.h"
#include "glm/glm.hpp"

namespace AIForGames
{
	class Agent;

    class GoToPointBehaviour :
        public Behaviour
    {
    public:
		void Enter(Agent* agent)
		{
			// blue when going to point
			agent->SetColor({ 0,0,255,255 });
			agent->Reset();
		}
		BehaviourResult Update(Agent* agent, float deltaTime)
		{
			if (IsMouseButtonPressed(0))
			{
				Vector2 mousePos = GetMousePosition();
				agent->GoTo(glm::vec2(mousePos.x, mousePos.y));
			}
		}
    };
}

