#pragma once
#include "../src/Application/Common/Abstractions/StageLoader.h"

namespace Arkanoid
{
	class StageReader : public StageLoader
	{
	public:
		std::vector<BrickDto> GetBrickSetup(int stageId);
	};

}
