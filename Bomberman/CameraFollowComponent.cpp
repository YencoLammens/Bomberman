#include "CameraFollowComponent.h"
#include "Transform.h"
#include <algorithm>
#include "Camera.h"

dae::CameraFollowComponent::CameraFollowComponent(GameObject* owner)
	: BaseComponent(owner)
{
}



void dae::CameraFollowComponent::Update(float)
{
	
	

}

void dae::CameraFollowComponent::LateUpdate()
{
	auto pos = GetOwner()->GetTransform()->GetWorldPosition();
	Camera::GetInstance().SetPosition({ pos.x - 480.f, 0.f, 0.f });
}

