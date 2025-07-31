#include "SpriteAnimatorComponent.h"
#include "AnimationClip.h"
#include "RenderComponent.h"
#include "GameObject.h"

dae::SpriteAnimatorComponent::SpriteAnimatorComponent(GameObject* owner, Texture2D* spriteSheet)
	: BaseComponent(owner), m_spriteSheet(spriteSheet)
{
	m_pRenderComponent = owner->GetComponent<RenderComponent>();
	if (!m_pRenderComponent)
		std::cerr << "SpriteAnimatorComponent: Missing RenderComponent on GameObject.\n";
}

void dae::SpriteAnimatorComponent::Update(float deltaTime)
{
	if (m_currentAnimation.empty() || m_animations.find(m_currentAnimation) == m_animations.end())
		return;

	const auto& clip = m_animations[m_currentAnimation];

	m_elapsedTime += deltaTime;
	if (m_elapsedTime >= clip.frameDuration)
	{
		m_elapsedTime -= clip.frameDuration;
		m_currentFrame++;

		if (m_currentFrame >= static_cast<int>(clip.frames.size()))
		{
			if (clip.loop)
				m_currentFrame = 0;
			else
				m_currentFrame = static_cast<int>(clip.frames.size()) - 1;
		}

		UpdateSprite();
	}
}

void dae::SpriteAnimatorComponent::RegisterAnimation(const std::string& name, const AnimationClip& clip)
{
	m_animations[name] = clip;

	// If this is the first animation added, auto-play it.
	if (m_currentAnimation.empty())
	{
		m_currentAnimation = name;
		m_currentFrame = 0;
		m_elapsedTime = 0.f;
		UpdateSprite();
	}
}

void dae::SpriteAnimatorComponent::Play(const std::string& name)
{
	if (name == m_currentAnimation)
		return; // Don't restart if already playing

	const auto it = m_animations.find(name);
	if (it != m_animations.end())
	{
		m_currentAnimation = name;
		m_currentFrame = 0;
		m_elapsedTime = 0.f;
		UpdateSprite();
	}
	else
	{
		std::cout << "SpriteAnimatorComponent::Play - Animation '" << name << "' not found.\n";
	}
}

void dae::SpriteAnimatorComponent::UpdateSprite()
{
	if (!m_pRenderComponent) return;

	const auto& clip = m_animations[m_currentAnimation];
	if (m_currentFrame < 0 || m_currentFrame >= static_cast<int>(clip.frames.size())) return;

	const auto& srcRect = clip.frames[m_currentFrame];
	m_pRenderComponent->SetSourceRect(srcRect);
}