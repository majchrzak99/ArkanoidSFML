#pragma once
#include <vector>
#include "../src/Application/Brick/Brick.h"
namespace Arkanoid {
	class BrickDto {
	public:
		int BrickStateId;
		int PosX;
		int PosY;
	};

	class StageLoader {
		public:
			virtual std::vector<BrickDto> GetBrickSetup(int stageId) = 0;
	};

}