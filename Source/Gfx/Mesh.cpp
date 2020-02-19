#include "Mesh.hpp"
#include <iostream>

namespace gfx {
	Mesh::Mesh() {
		glCreateVertexArrays(1, &vertexArray);
		glCreateBuffers(buffers.size(), buffers.data());
	
		glEnableVertexArrayAttrib(vertexArray, 0);
		glVertexArrayVertexBuffer(vertexArray, 0, getBuffer(MeshBuffer::VertexPositions), 0,  sizeof(glm::vec3));
		glVertexArrayAttribFormat(vertexArray, 0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexArrayAttribBinding(vertexArray, 0, 0);
	}

	Mesh::Mesh(Mesh&& mesh) noexcept {
		std::swap(vertexArray, mesh.vertexArray);
		std::swap(buffers, mesh.buffers);
		std::swap(vertexCount, mesh.vertexCount);
		std::swap(triangleCount, mesh.triangleCount);
	}

	Mesh::~Mesh() {
		glDeleteVertexArrays(1, &vertexArray);
		glDeleteBuffers(buffers.size(), buffers.data());
	}

	void Mesh::setVertexPositions(const data::VertexPositions& positions) {
		glNamedBufferStorage(getBuffer(MeshBuffer::VertexPositions), positions.size() * sizeof(glm::vec3), positions.data(), 0);
		vertexCount = positions.size();
	}

	void Mesh::setTriangles(const data::Triangles& triangles) {
		glNamedBufferStorage(getBuffer(MeshBuffer::Triangles), triangles.size() * sizeof(GLuint), triangles.data(), 0);
		triangleCount = triangles.size();
	}

	void Mesh::setData(const data::MeshData& data) {
		setVertexPositions(data.vertexPositions);
		setTriangles(data.triangles);
	}

	const GLuint& Mesh::getBuffer(MeshBuffer bufferName) const {
		return buffers.at(static_cast<size_t>(bufferName));
	}

	const GLsizei& Mesh::getVertexCount() const {
		return vertexCount;
	}

	const GLsizei& Mesh::getTriangleCount() const {
		return triangleCount;
	}

	void Mesh::render() const {
		glBindVertexArray(vertexArray);
		glBindBuffer(GL_ARRAY_BUFFER, getBuffer(MeshBuffer::VertexPositions));
		glDrawArrays(GL_TRIANGLES, 0, vertexCount);
	}
}