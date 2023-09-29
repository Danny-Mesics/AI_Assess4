#include "Behaviour.h"

AIForGames::BehaviourResult AIForGames::Behaviour::Tick(Agent* agent, float deltaTime)
{
    if (m_eBehaviourResult != Running)
    {
        OnInitialize();       
    }

    m_eBehaviourResult = Update(agent, deltaTime);

    return m_eBehaviourResult;
}
