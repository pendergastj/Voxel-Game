#pragma once
#include "Actor.hpp"
#include <functional>

namespace game {
	using ActorFilter = std::function<bool(const Actor&)>;
	using FilteredActors = std::vector<Actor*>;
	using UniqueActor = std::unique_ptr<Actor>;
	using ActorVector = std::vector<UniqueActor>;

	class ActorManager {
	public:
		// Spawns the actor, allows a custom transform too
		Actor* spawnActor(UniqueActor&& actor, const Transform& transform = Transform{});
		
		// Assigns the actors 'shouldBeDestroyed' attribute
		void destroyActor(Actor* actor);

		// Sends the event to all actors that satisfy the 'actorShouldHandleEvent' predicate
		void handleEvent(const sf::Event& event);

		// Updates all actors that satisfy the 'actorShouldUpdate' predicate
		void update(const float timeStep);

		// Renders all actors that satisfy the 'actorShouldRender' predicate
		void render();

		// Returns a vector of actor pointers that satisfy the predicate 'filter'
		FilteredActors filteredActors(const ActorFilter& filter) const;
	
		// Used to allow ranged for over the actors
		ActorVector::const_iterator begin() const;
		ActorVector::const_iterator end() const;
	private:

		// Erases all actors with attribute 'shouldBeDestroyed'
		void cleanActors();

		ActorVector actors;
	};
}