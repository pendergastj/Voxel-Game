#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

namespace data {
	using VertexPositions = std::vector<glm::vec3>;
	using Triangles = std::vector<GLuint>;

	struct MeshData {
		VertexPositions vertexPositions;
		Triangles triangles;
	};
}