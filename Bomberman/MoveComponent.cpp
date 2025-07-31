#include "MoveComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include <cmath>
#include "FSMComponent.h"
#include "BombermanState.h"
#include "IBombermanState.h"

dae::MoveComponent::MoveComponent(GameObject* owner, float speed)
	: BaseComponent(owner), m_speed(speed), m_direction({ 1, 0, 0 }), m_pendingDirection(0.f), m_previousDirection(m_direction)
{
}

void dae::MoveComponent::Update(float deltaTime)
{
	if (!m_canMove) return;

	auto* transform = GetOwner()->GetTransform();
	glm::vec3 currentPosition = transform->GetWorldPosition();

	if (!m_isMoving)
	{
		// Snap to grid
		currentPosition.x = std::round(currentPosition.x / m_tileSize) * m_tileSize;
		currentPosition.y = std::round(currentPosition.y / m_tileSize) * m_tileSize;
		transform->SetLocalPosition(currentPosition);

		if (m_pendingDirection == glm::vec3{ 0.f })
		{
			m_direction = glm::vec3{ 0.f };
			// Set idle state based on previous movement direction
			auto* fsm = GetOwner()->GetComponent<FSMComponent<BombermanState, IBombermanState>>();
			if (fsm)
			{
				if (m_previousDirection.x < 0.f)
					fsm->ChangeState(BombermanState::IdleLeft);
				else if (m_previousDirection.x > 0.f)
					fsm->ChangeState(BombermanState::IdleRight);
				else if (m_previousDirection.y < 0.f)
					fsm->ChangeState(BombermanState::IdleUp);
				else if (m_previousDirection.y > 0.f)
					fsm->ChangeState(BombermanState::IdleDown);
			}
			return;
		}

		glm::vec3 target = currentPosition + m_pendingDirection * m_tileSize;

		if (target.x < m_movementBounds.x || target.x > m_movementBounds.x + m_movementBounds.width - m_tileSize ||
			target.y < m_movementBounds.y || target.y > m_movementBounds.y + m_movementBounds.height - m_tileSize)
		{
			m_pendingDirection = glm::vec3{ 0.f };
			m_direction = glm::vec3{ 0.f };
			return;
		}

		m_previousDirection = m_pendingDirection;

		m_direction = m_pendingDirection;
		m_targetPosition = target;
		m_isMoving = true;
	}

	glm::vec3 directionToTarget = glm::normalize(m_targetPosition - currentPosition);
	glm::vec3 velocity = directionToTarget * m_speed * deltaTime;

	if (glm::length(m_targetPosition - currentPosition) <= glm::length(velocity))
	{
		transform->SetLocalPosition(m_targetPosition);
		m_isMoving = false;
	}
	else
	{
		transform->SetLocalPosition(currentPosition + velocity);
	}
}

void dae::MoveComponent::SetDirection(const glm::vec3& direction)
{
	m_pendingDirection = direction;

	if (!m_isMoving && m_canMove && direction != glm::vec3{ 0.f })
	{
		auto* fsm = GetOwner()->GetComponent<FSMComponent<BombermanState, IBombermanState>>();
		if (!fsm) return;

		if (direction.x < 0.f)
			fsm->ChangeState(BombermanState::WalkLeft);
		else if (direction.x > 0.f)
			fsm->ChangeState(BombermanState::WalkRight);
		else if (direction.y < 0.f)
			fsm->ChangeState(BombermanState::WalkUp);
		else if (direction.y > 0.f)
			fsm->ChangeState(BombermanState::WalkDown);
	}
}

void dae::MoveComponent::DisableMovement()
{
	m_canMove = false;
}

void dae::MoveComponent::EnableMovement()
{
	m_canMove = true;
}