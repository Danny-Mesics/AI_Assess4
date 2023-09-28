#include "Behaviour.h"

AIForGames::BehaviourResult AIForGames::Behaviour::Tick(Agent* agent, float deltaTime)
{
    if (m_eBehaviourResult != Running)
    {
        onInitialize();
    }

    m_eBehaviourResult = Update(agent, deltaTime);

    if (m_eBehaviourResult != Running)
    {
        onTerminate(m_eBehaviourResult);
    }
    return m_eBehaviourResult;
}
