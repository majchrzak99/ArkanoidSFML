#include "StageReader.h"

namespace Arkanoid {
	std::vector<BrickDto> StageReader::GetBrickSetup(int stageId)
	{
		std::vector<BrickDto> bricks;

		BrickDto dto;
		dto.BrickStateId = 3;

		dto.PosX = 0;
		dto.PosY = 0;
		bricks.push_back(dto);

		dto.PosX = 11;
		dto.PosY = 0;
		bricks.push_back(dto);

		return bricks;
	}
}

