#include "Composite.h"
#include <algorithm>

AIForGames::Composite* AIForGames::Composite::Add(Behaviour* child)
{
	m_children.push_back(child);
	//m_current = m_children.begin();
	return this;
}

void AIForGames::Composite::Remove(Behaviour* child)
{
	m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
	delete child;
}

void AIForGames::Composite::Clear()
{
	for (Behaviours::iterator it = m_children.begin(); it != m_children.end(); it++) {
		delete* it;
	}
	m_children.clear();
}
