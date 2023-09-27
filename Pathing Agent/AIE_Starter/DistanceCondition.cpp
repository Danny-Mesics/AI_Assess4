#include "DistanceCondition.h"
#include "glm/glm.hpp"
#include "Agent.h"

bool AIForGames::DistanceCondition::IsTrue(Agent* agent)
{
    return (glm::distance(agent->GetPosition(), agent->GetTargetAgent()->GetPosition()) < m_distance) == m_lessThan;
}
