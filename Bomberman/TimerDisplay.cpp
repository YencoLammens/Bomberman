#include "TimerDisplay.h"
#include "TextComponent.h"
#include "Camera.h"
#include "GameObject.h"
#include <format>

dae::TimerDisplay::TimerDisplay(GameObject* owner, int startTimeSec)
	: BaseComponent(owner), m_goUI(owner), m_remainingTime(startTimeSec), m_accumulator(0.0f)
{
	auto* text = m_goUI->GetComponent<TextComponent>();
	if (text)
	{
		text->SetText(std::format("TIME: {:03}", m_remainingTime));
	}
}

void dae::TimerDisplay::Update(float deltaTime)
{
	// Position UI relative to camera
	const glm::vec3 cameraPos = dae::Camera::GetInstance().GetPosition();
	glm::vec3 uiOffset{ cameraPos.x + 20.f, cameraPos.y + 20, 0.f };
	GetOwner()->GetTransform()->SetLocalPosition(uiOffset);

	if (m_timeUp) return;

	m_accumulator += deltaTime;
	if (m_accumulator >= 1.0f)
	{
		m_accumulator -= 1.0f;
		--m_remainingTime;

		if (m_remainingTime <= 0)
		{
			m_remainingTime = 0;
			m_timeUp = true;
		}

		// Update UI text
		if (auto* text = m_goUI->GetComponent<TextComponent>())
		{
			text->SetText(std::format("TIME: {:03}", m_remainingTime));
		}
	}
}