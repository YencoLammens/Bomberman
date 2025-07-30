#pragma once
#include <BaseComponent.h>
#include <iostream>
#include <unordered_map>

namespace dae 
{
	class Texture2D;
	struct AnimationClip;
	class RenderComponent;
	class SpriteAnimatorComponent : public BaseComponent
	{

	public:
		SpriteAnimatorComponent(GameObject* owner, Texture2D* spriteSheet);

		void Update(float deltaTime) override;
		void FixedUpdate(float) override {};
		void SetAnimation(const std::string& name, const AnimationClip& clip);

	private:
		std::unordered_map<std::string, AnimationClip> m_animations;
		std::string m_currentAnimation;
		float m_elapsedTime = 0.f;
		int m_currentFrame = 0;
		Texture2D* m_spriteSheet;
		RenderComponent* m_pRenderComponent = nullptr;

		void UpdateSprite();
	};
}


