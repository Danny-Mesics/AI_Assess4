#pragma once
#include "Composite.h"

namespace AIForGames
{
	class Agent;

	class Sequence:
		public Composite
	{
	public:
		virtual Status Update(Agent* agent, float deltaTime);
	protected:
		Behaviours::iterator m_current;
	};
}

