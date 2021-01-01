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
	protected:
		short MaxWidth = 12;
		short MaxHeight = 8;
	public:
		virtual std::vector<BrickDto> GetBrickSetup(int stageId) = 0;
		virtual short GetTotalStagesCount() = 0;
	};

}