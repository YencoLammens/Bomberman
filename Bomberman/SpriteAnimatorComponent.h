#pragma once
#include "BaseComponent.h"
#include <unordered_map>
#include <string>
#include <iostream>

namespace dae
{
	class Texture2D;
	struct AnimationClip;
	class RenderComponent;

	class SpriteAnimatorComponent final : public BaseComponent
	{
	public:
		SpriteAnimatorComponent(GameObject* owner, Texture2D* spriteSheet);

		void Update(float deltaTime) override;
		void FixedUpdate(float) override {}

		void RegisterAnimation(const std::string& name, const AnimationClip& clip);
		void Play(const std::string& name);

	private:
		void UpdateSprite();

		std::unordered_map<std::string, AnimationClip> m_animations;
		std::string m_currentAnimation;
		float m_elapsedTime = 0.f;
		int m_currentFrame = 0;

		Texture2D* m_spriteSheet = nullptr;
		RenderComponent* m_pRenderComponent = nullptr;
	};
}