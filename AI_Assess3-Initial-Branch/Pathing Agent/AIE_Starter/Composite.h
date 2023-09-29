#pragma once
#include "Behaviour.h"
#include <vector>

namespace AIForGames {
    class Composite :
        public Behaviour
    {
    public:
        Composite* Add(Behaviour* child);
        void Remove(Behaviour* child);
        void Clear();
        
    protected:
        typedef std::vector<Behaviour*> Behaviours;
        Behaviours m_children;
    };
}

