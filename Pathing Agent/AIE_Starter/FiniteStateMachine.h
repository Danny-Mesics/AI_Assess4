#pragma once
#include <vector>
#include "Behaviour.h"

/* This is the central code which stores a lists of all possible States. 
It operates on these agnostically ie all game-specific logic will go into 
the Conditions and Behaviours rather than here. 

It has one currently active State at any given time.*/
namespace AIForGames
{
    class State;

    class FiniteStateMachine : public Behaviour
    {
    private:
        std::vector<State*> m_states;

        State* m_currentState;
        State* m_newState;

    public:
        FiniteStateMachine(State* s) : m_currentState(s), m_newState(nullptr) {}
        virtual ~FiniteStateMachine();

        
        void Update(Agent* agent, float deltaTime);
        
        void AddState(State* state);
        void Enter(Agent* agent);
    };
}

