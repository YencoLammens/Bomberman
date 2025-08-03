#include "ScoreDisplay.h"
#include "TextComponent.h"
#include "ScoreComponent.h"
#include "Event.h"
#include <format>
#include "Camera.h"

dae::ScoreDisplay::ScoreDisplay(GameObject* goUI)
	:BaseComponent(goUI)
{
	m_goUI = goUI;
}

void dae::ScoreDisplay::Update(float /*deltaTime*/)
{
	const glm::vec3 cameraPos = dae::Camera::GetInstance().GetPosition();

	// For example, anchor top-left at 20,20 screen-space units from the camera view
	glm::vec3 uiOffset{ cameraPos.x + 500, cameraPos.y + 20.f, 0.f };

	GetOwner()->GetTransform()->SetLocalPosition(uiOffset);
}

void dae::ScoreDisplay::OnNotify(const GameEvent& event, GameObject* go)
{
	switch (event.Id)
	{
	case EventId::SCORE_CHANGED:
		std::string scoreString = std::format("{:05}", go->GetComponent<dae::ScoreComponent>()->GetScore());
		m_goUI->GetComponent<TextComponent>()->SetText(scoreString);
		break;
	}

}
