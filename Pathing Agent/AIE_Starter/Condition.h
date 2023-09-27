#pragma once

/*An abstract class with a virtual boolean test. 
We will derive from this to provide game-specific 
logic to drive our state Transitions.*/

namespace AIForGames
{
	class Agent;

	class Condition
	{
	public:
		virtual bool IsTrue(Agent* agent) = 0;
	};	
}

