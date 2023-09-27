#pragma once
#include <vector>
#include "FollowBehaviour.h"
#include "WanderBehaviour.h"
// Class Notes:

        // State class note:

                /* A state has a collection of Behaviours, and a collection of Transitions. 
                An example state might be a follow state, which holds a FollowBehaviour from 
                last lab, and Conditions for when to switch to other states. 

                We will not need to inherit from this class, but will put our game-specific 
                logic into the Behaviours it references.*/

// ---  ---  ---

        // Transition struct note:

                /* A Transition stores a Condition and a target State pointer.
                If the Condition is met, the parent FSM will switch to the target state.
                E.g “If close to the player, switch to follow state”.
                The Transition struct/class won’t need to be inherited from.*/

namespace AIForGames 
{
    // Forward Declarations
    class Behaviour;
    class Agent;
    class Condition;


    class State // See class notes
    {
    public:
        
        struct Transition // See class notes
        {
            Condition* condition;
            State* targetState;
        };

    private:
        std::vector<Behaviour*> m_behaviours;
        std::vector<Transition> m_transitions;

    public:
        State(Behaviour* behaviour);
        ~State();

        virtual void Enter(Agent* agent);
        virtual void Update(Agent* agent, float deltaTime);
        //virtual void Exit(Agent* agent);

        void AddTransition(Condition* condition, State* state);
        std::vector<Transition> GetTransitions() { return m_transitions; };
        //std::vector<Behaviour*> GetBehaviours() { return m_behaviours; };
    };
}

