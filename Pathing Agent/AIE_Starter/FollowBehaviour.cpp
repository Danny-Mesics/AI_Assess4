#include "FollowBehaviour.h"
#include "Agent.h"
#include "Pathfinding.h"
namespace AIForGames
{

	void FollowBehaviour::Enter(Agent* agent)
	{
		// red when following
		agent->SetColor({ 255,0,0,255 });
		agent->SetPathColor({ 255,0,0,255 });
		agent->Reset();
	}

	void FollowBehaviour::Update(Agent* agent, float deltaTime)
	{
		Agent* target = agent->GetTargetAgent();

		float dist = glm::length(target->GetPosition() - lastTargetPosition);
		if (dist > agent->GetNodeMap()->GetCellSize())
		{
			lastTargetPosition = target->GetPosition();
			agent->GoTo(lastTargetPosition);
		}
	}
}