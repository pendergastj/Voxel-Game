#include "ActorManager.hpp"

namespace game {
	Actor* ActorManager::spawnActor(UniqueActor&& actor, const Transform& transform) {
		actor->setAttributes();
		actor->transform = transform;

		actors.push_back(std::move(actor));
		return actors.back().get();
	}

	void ActorManager::destroyActor(Actor* actor) {
		actor->attributes.shouldBeDestroyed = true;
	}

	void ActorManager::handleEvent(const sf::Event& event) {
		for (Actor* actor : filteredActors(actorShouldHandleEvents))
			actor->handleEvent(event);
	}

	void ActorManager::update(const float timeStep) {
		cleanActors();

		for (Actor* actor : filteredActors(actorShouldUpdate))
			actor->update(timeStep);
	}

	void ActorManager::render() {
		for (Actor* actor : filteredActors(actorShouldRender))
			actor->render();
	}

	FilteredActors ActorManager::filteredActors(const ActorFilter& filter) const {
		FilteredActors candidates;

		for (const auto& candidate : actors) {
			if (filter(*candidate))
				candidates.push_back(candidate.get());
		}

		return candidates;
	}

	ActorVector::const_iterator ActorManager::begin() const {
		return actors.begin();
	}

	ActorVector::const_iterator ActorManager::end() const {
		return actors.end();
	}

	void ActorManager::cleanActors() {
		for (auto iter = actors.begin(); iter != actors.end(); ) {
			if (actorShouldBeDestroyed(**iter)) {
				iter = actors.erase(iter);
			}
			else {
				++iter;
			}
		}
	}
}