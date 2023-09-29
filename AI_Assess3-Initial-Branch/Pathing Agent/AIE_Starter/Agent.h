#pragma once

#include "raylib.h"
#include "PathAgent.h"
#include "Behaviour.h"


namespace AIForGames
{
	class Behaviour;
	class NodeMap;

	class Agent
	{
	public:
		Agent(NodeMap* _nodeMap);
		~Agent() { delete m_BehaviourTree; }

		void Update(float deltaTime);
		void Draw();
		void GoTo(glm::vec2 point);
		void GoTo(Node* node);
		void SetNode(Node* node);
		bool PathComplete();
		Node* GetRandomNode();
		Agent* GetTargetAgent();
		void SetTargetAgent(Agent* agent);
		glm::vec2 GetPosition();
		NodeMap* GetNodeMap();
		void SetColor(Color c);
		void SetPathColor(Color c);
		void SetSpeed(float s);
		void Reset();
	protected:
	private:
		PathAgent m_pathAgent;
		Behaviour* m_BehaviourTree;
		NodeMap* m_nodeMap;
		Agent* m_targetAgent = nullptr;
		Color m_color;
	};
}