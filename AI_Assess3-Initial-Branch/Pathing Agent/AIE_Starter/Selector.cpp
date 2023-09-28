#include "Selector.h"

AIForGames::Selector::~Selector()
{
	Clear();
}


void AIForGames::Selector::OnInitialize()
{
	m_current = m_children.begin();
}

AIForGames::BehaviourResult AIForGames::Selector::Update(Agent* agent, float deltaTime)
{
    // Keep going until a child behavior says its running.
    while (true)
    {
        BehaviourResult s = (*m_current)->tick(agent, deltaTime);

        // If the child succeeds, or keeps running, do the same.
        if (s != Failure)
        {
            return s;
        }

        // Hit the end of the array, it didn't end well...
        if (++m_current == m_children.end())
        {
            return Failure;
        }
    }
}