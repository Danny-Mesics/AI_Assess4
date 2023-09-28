#pragma once
#include "Behaviour.h"
#include "raylib.h"
#include "glm/glm.hpp"
#include "Agent.h"
#include "Selector.h"
#include "Sequence.h"
#include "Pathfinding.h"

namespace AIForGames
{
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

	class FollowBehaviour :
		public Behaviour
	{
	private:
		glm::vec2 lastTargetPosition;

	public:
		void Enter(Agent* agent)
		{
			// red when following
			agent->SetColor({ 255,0,0,255 });
			agent->SetPathColor({ 255,0,0,255 });
			agent->Reset();
		}

		BehaviourResult Update(Agent* agent, float deltaTime)
		{
			Agent* target = agent->GetTargetAgent();

			float dist = glm::length(target->GetPosition() - lastTargetPosition);
			if (dist > agent->GetNodeMap()->GetCellSize())
			{
				lastTargetPosition = target->GetPosition();
				agent->GoTo(lastTargetPosition);
			} // Extract Conditions from these behaviours and create some new behaviours, also build the tree
			return Success;
		}
	};

	class WanderBehaviour :
		public Behaviour
	{
	public:
		void Enter(Agent* agent)
		{
			// green when wandering
			agent->SetColor({ 0,255,0,255 });
			agent->SetPathColor({ 0,255,0,255 });
			agent->Reset();
		}
		BehaviourResult Update(Agent* agent, float deltaTime)
		{
			if (agent->PathComplete())
				agent->GoTo(agent->GetRandomNode());
			return Success;
		}
	};
}