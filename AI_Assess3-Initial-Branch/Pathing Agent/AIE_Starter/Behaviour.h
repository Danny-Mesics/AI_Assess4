#pragma once
namespace AIForGames
{
	enum BehaviourResult
	{
		Invalid,
		Success,
		Failure,
		Running
	};

	class Agent;

	class Behaviour
	{
	public:
		virtual void Enter(Agent* agent) {};

	public:
		Behaviour() : m_eBehaviourResult(Invalid) {}
		virtual ~Behaviour() {}

	public:
		virtual BehaviourResult Update(Agent* agent, float deltaTime) = 0;
		virtual void OnInitialize() {}

		BehaviourResult Tick(Agent* agent, float deltaTime);
	private:
		BehaviourResult m_eBehaviourResult;
	};
}

