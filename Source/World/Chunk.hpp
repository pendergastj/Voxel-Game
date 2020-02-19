#pragma once
#include "../Game/Actor.hpp"
#include "../Data/VoxelData.hpp"

namespace world {
	using ChunkVoxelData = data::VoxelData<32>;
	
	class Chunk : public game::Actor {
	public:
		void setAttributes() override;
		virtual void update(const float timeStep) override;
		virtual void render() override;
		ChunkVoxelData voxelData;
	};
}