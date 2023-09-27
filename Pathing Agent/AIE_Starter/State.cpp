#include "State.h"
#include "Behaviour.h"

struct Transition;

AIForGames::State::State(Behaviour* behaviour)
{
    m_behaviours.push_back(behaviour);
}

AIForGames::State::~State()
{
    // we own the behaviours assigned to us
    for (Behaviour* b : m_behaviours)
        delete b;

    // we also own the Conditions in each Transition
        // (but the states are references, so don’t clean them up here)
    for (Transition t : m_transitions)
        delete t.condition;
}

void AIForGames::State::Enter(Agent* agent)
{
    for (Behaviour* b : m_behaviours) {
        b->Enter(agent);
    }
}

void AIForGames::State::Update(Agent* agent, float deltaTime)
{
    for (Behaviour* b : m_behaviours)
        b->Update(agent, deltaTime);
}

//void AIForGames::State::Exit(Agent* agent)
//{
//    for (Behaviour* b : GetBehaviours()) {
//        b->Exit(agent);
//    }
//}

void AIForGames::State::AddTransition(Condition* condition, State* state)
{
    Transition t;
    t.condition = condition;
    t.targetState = state;
    m_transitions.push_back(t);
}



