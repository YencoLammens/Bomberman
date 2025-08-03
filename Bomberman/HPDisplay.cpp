#include "HPDisplay.h"
#include "TextComponent.h"
#include "HealthComponent.h"
#include "Event.h"
#include <format>
#include "Camera.h"

dae::HPDisplay::HPDisplay(GameObject* goUI)
	: BaseComponent(goUI), m_goUI(goUI)
{
}

void dae::HPDisplay::Update(float /*deltaTime*/)
{
	const glm::vec3 cameraPos = dae::Camera::GetInstance().GetPosition();

	glm::vec3 uiOffset{ cameraPos.x + 700, cameraPos.y + 20.f, 0.f };

	GetOwner()->GetTransform()->SetLocalPosition(uiOffset);
}

void dae::HPDisplay::LateUpdate()
{
	
}

void dae::HPDisplay::OnNotify(const GameEvent& event, GameObject* go)
{
	if (event.Id != EventId::HEALTH_CHANGED || !go) return;

	const auto healthComp = go->GetComponent<HealthComponent>();
	if (!healthComp) return;

	const int hp = healthComp->GetHealth();

	const std::string hpString = std::format("HP: {:02}", hp);
	m_goUI->GetComponent<TextComponent>()->SetText(hpString);
}