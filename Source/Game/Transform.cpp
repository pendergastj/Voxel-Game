#include "Transform.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace game {
	void Transform::translate(const glm::vec3& translation) {
		position += translation * orientation;
	}

	void Transform::rotate(const glm::vec3& rotation) {
		orientation = glm::rotate(orientation, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		orientation = glm::rotate(orientation, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		orientation = glm::rotate(orientation, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	}

	float Transform::distance(const Transform& transform) const {
		return glm::distance(position, transform.position);
	}

	glm::mat4 Transform::asMatrix() const {
		glm::mat4 matrix(1.0f);
		matrix = glm::toMat4(orientation);
		matrix = glm::translate(matrix, position);
		return matrix;
	}
}
