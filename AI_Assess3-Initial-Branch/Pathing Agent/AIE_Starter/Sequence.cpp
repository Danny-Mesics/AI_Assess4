#include "Sequence.h"

AIForGames::Sequence::~Sequence()
{
	Clear();
}

void AIForGames::Sequence::OnInitialize()
{
	m_current = m_children.begin();
}

AIForGames::BehaviourResult AIForGames::Sequence::Update(Agent* agent, float deltaTime)
{
    // Keep going until a child behavior says it's running.
    while (true)
    {
        BehaviourResult s = (*m_current)->tick(agent, deltaTime);

        // If the child fails, or keeps running, do the same.
        if (s != Success)
        {
            return s;
        }

        // Hit the end of the array, job done!
        if (++m_current == m_children.end())
        {
            return Success;
        }
    }
}

