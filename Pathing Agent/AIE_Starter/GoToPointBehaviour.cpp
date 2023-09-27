#include "GoToPointBehaviour.h"
#include "raylib.h"
#include "glm/glm.hpp"
#include "Agent.h"

namespace AIForGames
{
	void GoToPointBehaviour::Enter(Agent* agent)
	{
		// blue when going to point
		agent->SetColor({ 0,0,255,255 });
		agent->Reset();
	}
	void GoToPointBehaviour::Update(Agent* agent, float deltaTime)
	{
		if (IsMouseButtonPressed(0))
		{
			Vector2 mousePos = GetMousePosition();
			agent->GoTo(glm::vec2(mousePos.x, mousePos.y));
		}
	}
}