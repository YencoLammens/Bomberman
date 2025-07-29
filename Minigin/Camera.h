#pragma once
#include "glm.hpp"
#include "Singleton.h"

namespace dae
{
	class Camera final : public Singleton<Camera>
	{
	public:
		void SetPosition(const glm::vec3& pos);
		glm::vec3 GetPosition() const;

		void SetScreenSize(float width, float height);
		void SetMapSize(float width, float height);

	private:
		glm::vec3 m_Position{ 0.0f, 0.0f, 0.0f };
		float m_ScreenWidth{ 0.f };
		float m_ScreenHeight{ 0.f };
		float m_MapWidth{ 0.f };
		float m_MapHeight{ 0.f };
	};
}