#include "Game.hpp"

namespace game {
	Game::Game(sf::RenderWindow& window) :
		window(window) {
	}

	void Game::setState(std::unique_ptr<State>&& newState) {
		state = std::move(newState);
	}

	void Game::run() {
		float accumulatedTime = 0.0f;

		while (window.isOpen()) {
			const float deltaTime = clock.restart().asSeconds();
			accumulatedTime += deltaTime;

			pollEvents();

			while (accumulatedTime >= TIME_STEP) {
				pollEvents();
				state->update(TIME_STEP);
				accumulatedTime -= TIME_STEP;
			}

			glClear(GL_COLOR_BUFFER_BIT);
			state->render();
			window.display();
		}
	}

	void Game::pollEvents() {
		for (sf::Event event; window.pollEvent(event); ) {
			if (event.type == sf::Event::Closed)
				window.close();
			else {
				state->handleEvent(event);
			}
		}
	}
}