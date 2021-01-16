#pragma once
#include "../src/Application/Common/Abstractions/StageLoader.h"
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>


namespace Arkanoid
{
	/// stage loader implementation
	class StageReader : public StageLoader
	{
		const std::string _path = "stages/";
	public:
		std::vector<BrickDto> GetBrickSetup(int stageId);
		short GetTotalStagesCount();
	};

}
