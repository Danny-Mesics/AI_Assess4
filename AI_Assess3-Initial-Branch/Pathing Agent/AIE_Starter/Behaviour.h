#pragma once
namespace AIForGames
{
	enum BehaviourResult
	{
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
		Behaviour() : m_eBehaviourResult(Running) {}
		virtual ~Behaviour() {}

	public:
		virtual BehaviourResult Update(Agent* agent, float deltaTime) = 0;
		virtual void onInitialize() {}
		virtual void onTerminate(BehaviourResult status) {}

		BehaviourResult Tick(Agent* agent, float deltaTime);
	private:
		BehaviourResult m_eBehaviourResult;
	};
}

