#include "Actor.hpp"

namespace game {
	void Actor::render() {
		if (shader) {
			sf::Shader::bind(shader.get());
		}
		mesh.render();
	}

	bool actorShouldHandleEvents(const Actor& actor) {
		return actor.attributes.shouldHandleEvent;
	}

	bool actorShouldUpdate(const Actor& actor) {
		return actor.attributes.shouldUpdate;
	}

	bool actorShouldRender(const Actor& actor) {
		return actor.attributes.shouldRender;
	}

	bool actorShouldBeDestroyed(const Actor& actor) {
		return actor.attributes.shouldBeDestroyed;
	}

	bool actorHasShader(const Actor& actor) {
		return actor.shader.get();
	}
}
