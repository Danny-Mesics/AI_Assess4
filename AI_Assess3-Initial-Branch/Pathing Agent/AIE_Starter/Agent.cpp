#include "Agent.h"
#include "Behaviour.h"
#include "Pathfinding.h"
#include "LeafNodeBehaviours.h"

namespace AIForGames
{
	Agent::Agent(NodeMap* _nodeMap) : m_BehaviourTree(nullptr), m_nodeMap(_nodeMap), m_color({ 255,255,0,255 }), m_pathAgent(_nodeMap) {
			m_pathAgent.SetSpeed(128);
			m_BehaviourTree =
				(new Selector())
				->Add(
					(new Sequence())
						->Add(new DistanceCondition(8.0f * m_nodeMap->GetCellSize(), false))
						->Add(new FollowBehaviour()))
				->Add(
					(new Sequence())
						->Add(new DistanceCondition(20.0f * m_nodeMap->GetCellSize(), true))
						->Add(new WanderBehaviour()));


			m_BehaviourTree->Enter(this);
	}

	void Agent::Update(float deltaTime)
	{
		if (m_BehaviourTree)
			m_BehaviourTree->Tick(this, deltaTime);
		m_pathAgent.Update(deltaTime);
	}

	void Agent::Draw()
	{
		m_pathAgent.Draw();
	}

	void Agent::GoTo(glm::vec2 point)
	{
		Node* end = m_nodeMap->GetClosestNode(point);
		m_pathAgent.GoToNode(end);
	}

	void Agent::GoTo(Node* node)
	{
		m_pathAgent.GoToNode(node);
	}

	void Agent::SetNode(Node* node)
	{
		m_pathAgent.SetNode(node);
	}
	bool Agent::PathComplete()
	{
		return m_pathAgent.IsEmpty();
	}
	Node* Agent::GetRandomNode()
	{
		return m_nodeMap->GetRandomNode();
	}
	Agent* Agent::GetTargetAgent()
	{
		return m_targetAgent;
	}
	void Agent::SetTargetAgent(Agent* agent)
	{
		m_targetAgent = agent;
	}
	glm::vec2 Agent::GetPosition()
	{
		return m_pathAgent.GetPosition();
	}
	NodeMap* Agent::GetNodeMap()
	{
		return m_nodeMap;
	}
	void Agent::SetColor(Color c)
	{
		m_pathAgent.SetColor(c);
	}
	void Agent::SetPathColor(Color c)
	{
		m_pathAgent.SetPathColour(c);
	}
	void Agent::SetSpeed(float s)
	{
		m_pathAgent.SetSpeed(s);
	}
	void Agent::Reset()
	{
		m_pathAgent.Reset();
	}
}