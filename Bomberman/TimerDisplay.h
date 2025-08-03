#pragma once
#include "BaseComponent.h"
#include <chrono>

namespace dae
{
	class GameObject;
	class TimerDisplay final : public BaseComponent
	{
	public:
		TimerDisplay(GameObject* owner, int startTimeSec = 180);

		void Update(float deltaTime) override;
		void LateUpdate() override {}
		void FixedUpdate(float) override {}

	private:
		GameObject* m_goUI;
		int m_remainingTime; // in seconds
		float m_accumulator; // for counting full seconds
		bool m_timeUp = false;
	};
}