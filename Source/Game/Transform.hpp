#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace game {
	class Transform {
	public:
		void translate(const glm::vec3& translation);
		void rotate(const glm::vec3& rotation);
		float distance(const Transform& transform) const;
		glm::mat4 asMatrix() const;

		glm::vec3 position;
		glm::quat orientation;
	};
}