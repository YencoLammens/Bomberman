#include "Camera.h"
#include <algorithm>

void dae::Camera::SetScreenSize(float width, float height)
{
    m_ScreenWidth = width;
    m_ScreenHeight = height;
}

void dae::Camera::SetMapSize(float width, float height)
{
    m_MapWidth = width;
    m_MapHeight = height;
}

void dae::Camera::SetPosition(const glm::vec3& pos)
{
    glm::vec3 clamped = pos;
    clamped.x = std::clamp(pos.x, 0.f, std::max(0.f, m_MapWidth - m_ScreenWidth));
    clamped.y = std::clamp(pos.y, 0.f, std::max(0.f, m_MapHeight - m_ScreenHeight));
    m_Position = clamped;
}

glm::vec3 dae::Camera::GetPosition() const
{
    return m_Position;
}