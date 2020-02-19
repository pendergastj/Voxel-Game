#pragma once
#include "Array3D.hpp"

namespace data {

	enum class Voxel : bool {Empty, Solid};
	
	template<int Size>
	using VoxelData = Array3D<Size, Voxel>;
}