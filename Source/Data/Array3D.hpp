#pragma once
#include <array>
#include <glm/vec3.hpp>

namespace data {
	// Simple 3D array
	template<int Size, typename Type>
	class Array3D {
	public:
		const Type& get(const glm::ivec3& position) const {
			return data.at(index(position));
		}

		void set(const glm::ivec3& position, Type Type) {
			data.at(index(position), Type);
		}

		int size() const {
			return Size;
		}

	private:
		int index(const glm::ivec3& position) {
			return position.x * Size + (position.y * Size + position.z);
		}

		std::array<Type, Size * Size * Size> data;
	};
}