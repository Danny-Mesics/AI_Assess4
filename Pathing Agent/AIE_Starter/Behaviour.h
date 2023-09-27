#pragma once
namespace AIForGames
{
	enum Status {
		BH_INVALID,
		BH_SUCCESS,
		BH_FAILURE,
		BH_RUNNING,
	};

	class Agent;

	class Behaviour
	{
	private:
		Status m_eStatus;
	public:
		Behaviour() : m_eStatus(BH_INVALID) {}

		virtual void Enter(Agent* agent) {};

		virtual Status Update(Agent* agent, float deltaTime) = 0;
		Status Tick(Agent* agent, float deltaTime);

		Status GetStatus() const;


		virtual void OnInitialize() {}
		virtual void OnTerminate(Status status) {}


		/*virtual void Exit(Agent* agent) {};*/
	};
}

