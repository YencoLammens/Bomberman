#pragma once
#include "BaseComponent.h"
#include "GameObject.h"

namespace dae 
{
	class CameraFollowComponent : public BaseComponent
	{
	public:
		CameraFollowComponent(GameObject* owner);
		void Update(float) override;
		void FixedUpdate(float) override {}
		void LateUpdate() override;
	};

}

