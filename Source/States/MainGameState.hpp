#pragma once
#include "../Game/State.hpp"

namespace states {
	class MainGameState : public game::State {
	public:
		MainGameState();
		virtual void update(const float timeStep) override;
		virtual void render() override;
		virtual void handleEvent(const sf::Event& event) override;
	};
}