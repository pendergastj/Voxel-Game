#include "MainGameState.hpp"

namespace states {
	MainGameState::MainGameState() {
		auto triangle = actorManager.spawnActor(std::make_unique<game::Actor>());
		triangle->mesh.setData(
			data::MeshData{
				data::VertexPositions {
					glm::vec3(-1.0f, -1.0f, 0.0f),
					glm::vec3( 1.0f, -1.0f, 0.0f),
					glm::vec3( 0.0f,  1.0f, 0.0f)
				},
				data::Triangles {0, 1, 2},
			}
		);
	}

	void MainGameState::update(const float timeStep) {
		actorManager.update(timeStep);
	}

	void MainGameState::render() {
		actorManager.render();
	}

	void MainGameState::handleEvent(const sf::Event& event) {
		actorManager.handleEvent(event);
	}
}