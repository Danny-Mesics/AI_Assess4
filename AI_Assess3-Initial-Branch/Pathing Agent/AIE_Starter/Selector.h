#pragma once
#include "Composite.h"

namespace AIForGames {
	class Selector :
		public Composite
	{
	protected:
		virtual ~Selector();

		virtual void OnInitialize();

		virtual BehaviourResult Update(Agent* agent, float deltaTime);

		Behaviours::iterator m_current;
	};

}

