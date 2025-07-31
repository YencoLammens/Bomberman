#include "IBombermanState.h"
#include "GameObject.h"
#include "SpriteAnimatorComponent.h"

void dae::IdleDownState::Enter(dae::GameObject& /*owner*/)
{
    //auto* animator = owner.GetComponent<dae::SpriteAnimatorComponent>();
    /*if (animator)
        animator->RegisterAnimation("Idle");*/
}

void dae::IdleDownState::Exit(dae::GameObject&)
{
}

void dae::IdleDownState::Update(dae::GameObject*, float)
{
}

void dae::IdleDownState::HandleInput(dae::GameObject*)
{
}

void dae::IdleDownState::HandleEvent(dae::GameObject*)
{
}
