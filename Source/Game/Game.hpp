#pragma once
#include <memory>
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../Gfx/Mesh.hpp"

namespace game {
	class Game {
	public:
		constexpr static float TIME_STEP = 1.0f / 60.0f;

		Game(sf::RenderWindow& window);
		void setState(std::unique_ptr<State>&& newState);
		void run();
	private:
		sf::Clock clock;
		sf::RenderWindow& window;
		std::unique_ptr<State> state;
		void pollEvents();
	};
}