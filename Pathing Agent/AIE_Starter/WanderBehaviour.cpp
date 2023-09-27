#include "WanderBehaviour.h"
#include "Agent.h"
namespace AIForGames
{
	void WanderBehaviour::Enter(Agent* agent)
	{
		// green when wandering
		agent->SetColor({ 0,255,0,255 });
		agent->SetPathColor({ 0,255,0,255 });
		agent->Reset();
	}
	void WanderBehaviour::Update(Agent* agent, float deltaTime)
	{
		if (agent->PathComplete())
			agent->GoTo(agent->GetRandomNode());
	}
}