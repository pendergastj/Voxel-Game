#pragma once
#include <memory>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Window/Event.hpp>

#include "Transform.hpp"
#include "../Gfx/Mesh.hpp"

namespace game {
	struct ActorAttributes {
		bool shouldHandleEvent = false;
		bool shouldUpdate = false;
		bool shouldRender = false;
		bool shouldBeDestroyed = false;
	};

	class Actor {
	public:
		virtual void setAttributes() {}
		virtual void handleEvent(const sf::Event& event) {}
		virtual void update(const float timeStep) {}
		virtual void render();

		gfx::Mesh mesh;
		std::shared_ptr<sf::Shader> shader;
		ActorAttributes attributes;
		Transform transform;
	};

	// Utility predicates
	bool actorShouldHandleEvents(const Actor& actor);
	bool actorShouldUpdate(const Actor& actor);
	bool actorShouldRender(const Actor& actor);
	bool actorShouldBeDestroyed(const Actor& actor);
	bool actorHasShader(const Actor& actor);
}