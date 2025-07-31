#include "IBombermanState.h"
#include "GameObject.h"
#include "SpriteAnimatorComponent.h"

void dae::IdleDownState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("IdleDown");
}
void dae::IdleDownState::Exit(dae::GameObject&) {}
void dae::IdleDownState::Update(dae::GameObject*, float) {}
void dae::IdleDownState::HandleInput(dae::GameObject*) {}
void dae::IdleDownState::HandleEvent(dae::GameObject*) {}

void dae::IdleUpState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("IdleUp");
}
void dae::IdleUpState::Exit(dae::GameObject&) {}
void dae::IdleUpState::Update(dae::GameObject*, float) {}
void dae::IdleUpState::HandleInput(dae::GameObject*) {}
void dae::IdleUpState::HandleEvent(dae::GameObject*) {}

void dae::IdleRightState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("IdleRight");
}
void dae::IdleRightState::Exit(dae::GameObject&) {}
void dae::IdleRightState::Update(dae::GameObject*, float) {}
void dae::IdleRightState::HandleInput(dae::GameObject*) {}
void dae::IdleRightState::HandleEvent(dae::GameObject*) {}

void dae::IdleLeftState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("IdleLeft");
}
void dae::IdleLeftState::Exit(dae::GameObject&) {}
void dae::IdleLeftState::Update(dae::GameObject*, float) {}
void dae::IdleLeftState::HandleInput(dae::GameObject*) {}
void dae::IdleLeftState::HandleEvent(dae::GameObject*) {}

void dae::WalkingDownState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("WalkDown");
}
void dae::WalkingDownState::Exit(dae::GameObject&) {}
void dae::WalkingDownState::Update(dae::GameObject*, float) {}
void dae::WalkingDownState::HandleInput(dae::GameObject*) {}
void dae::WalkingDownState::HandleEvent(dae::GameObject*) {}

void dae::WalkingUpState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("WalkUp");
}
void dae::WalkingUpState::Exit(dae::GameObject&) {}
void dae::WalkingUpState::Update(dae::GameObject*, float) {}
void dae::WalkingUpState::HandleInput(dae::GameObject*) {}
void dae::WalkingUpState::HandleEvent(dae::GameObject*) {}

void dae::WalkingRightState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("WalkRight");
}
void dae::WalkingRightState::Exit(dae::GameObject&) {}
void dae::WalkingRightState::Update(dae::GameObject*, float) {}
void dae::WalkingRightState::HandleInput(dae::GameObject*) {}
void dae::WalkingRightState::HandleEvent(dae::GameObject*) {}

void dae::WalkingLeftState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("WalkLeft");
}
void dae::WalkingLeftState::Exit(dae::GameObject&) {}
void dae::WalkingLeftState::Update(dae::GameObject*, float) {}
void dae::WalkingLeftState::HandleInput(dae::GameObject*) {}
void dae::WalkingLeftState::HandleEvent(dae::GameObject*) {}

void dae::DyingState::Enter(dae::GameObject& owner)
{
    if (auto* animator = owner.GetComponent<SpriteAnimatorComponent>())
        animator->Play("Die");
}
void dae::DyingState::Exit(dae::GameObject&) {}
void dae::DyingState::Update(dae::GameObject*, float) {}
void dae::DyingState::HandleInput(dae::GameObject*) {}
void dae::DyingState::HandleEvent(dae::GameObject*) {}