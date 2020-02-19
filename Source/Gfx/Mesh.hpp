#pragma once
#include <array>
#include "../Data/MeshData.hpp"

namespace gfx {
	enum class MeshBuffer {
		VertexPositions,
		Triangles,
		Count
	};

	class Mesh {
	public:
		Mesh();
		Mesh(Mesh&& mesh) noexcept;
		~Mesh();
		Mesh(const Mesh&) = delete;
		Mesh& operator = (const Mesh&) = delete;

		// Manipulate mesh data 
		void setVertexPositions(const data::VertexPositions& positions);
		void setTriangles(const data::Triangles& triangles);
		void setData(const data::MeshData& data);

		const GLuint& getBuffer(MeshBuffer bufferName) const;
		const GLsizei& getVertexCount() const;
		const GLsizei& getTriangleCount() const;

		void render() const;
	private:
		GLuint vertexArray{ 0u };
		GLsizei vertexCount{ 0u };
		GLsizei triangleCount{ 0u };
		std::array<GLuint, static_cast<int>(MeshBuffer::Count)> buffers;
	};
}