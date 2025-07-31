#pragma once
namespace dae 
{
    class GameObject;
    class IBombermanState
    {
    public:
        virtual ~IBombermanState() = default;

        virtual void Enter(GameObject& owner) = 0;
        virtual void Exit(GameObject& owner) = 0;
        virtual void Update(GameObject* owner, float deltaTime) = 0;
        virtual void HandleInput(GameObject* owner) = 0;
        virtual void HandleEvent(GameObject* owner) = 0;
    };

    class IdleDownState : public dae::IBombermanState
    {
    public:
        void Enter(dae::GameObject& owner) override;
        void Exit(dae::GameObject& owner) override;
        void Update(dae::GameObject* owner, float deltaTime) override;
        void HandleInput(dae::GameObject* owner) override;
        void HandleEvent(dae::GameObject* owner) override;
    };

}

