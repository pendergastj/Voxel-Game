#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "../Game/ActorManager.hpp"

namespace game {
	class State {
	public:
		virtual void update(const float timeStep) = 0;
		virtual void render() = 0;
		virtual void handleEvent(const sf::Event& event) = 0;
		virtual ~State() {}

		ActorManager actorManager;
	};
}