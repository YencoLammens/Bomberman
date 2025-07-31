#pragma once
#include "BaseComponent.h"
#include <memory>
#include <unordered_map>

namespace dae
{
    template<typename StateId, typename State>
    class FSMComponent : public BaseComponent
    {
    public:
        FSMComponent(GameObject* owner)
            : BaseComponent(owner), m_currentState(nullptr)
        {
        }

        void Update(float deltaTime) override
        {
            if (m_currentState)
                m_currentState->Update(GetOwner(), deltaTime);
        }

		void FixedUpdate(float /*deltaTime*/) override
		{
			// Implement fixed update logic if needed
		}

        void HandleInput()
        {
            if (m_currentState)
                m_currentState->HandleInput(GetOwner());
        }

        void HandleEvent()
        {
            if (m_currentState)
                m_currentState->HandleEvent(GetOwner());
        }

        void ChangeState(StateId newStateId)
        {
            if (m_currentState)
                m_currentState->Exit(*GetOwner());

            m_currentState = m_statesMap[newStateId].get();
            m_currentStateId = newStateId;

            if (m_currentState)
                m_currentState->Enter(*GetOwner());
        }

        void AddState(StateId id, std::unique_ptr<State> state)
        {
            m_statesMap[id] = std::move(state);
        }

        StateId GetCurrentStateId() const { return m_currentStateId; }
        State* GetCurrentState() const { return m_currentState; }

    private:
        std::unordered_map<StateId, std::unique_ptr<State>> m_statesMap;
        State* m_currentState;
        StateId m_currentStateId;
    };
}