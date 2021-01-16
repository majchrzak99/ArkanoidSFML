#pragma once
#include <vector>
#include "../src/Application/Brick/Brick.h"
namespace Arkanoid {
	/// dto using to fetch brick setup
	class BrickDto {
	public:
		int BrickStateId;
		int PosX;
		int PosY;
	};

	/// interface used to fetch brick setup for stage
	class StageLoader {
	protected:
		short MaxWidth = 12;
		short MaxHeight = 8;
	public:
		/// fetch brick setup
		/// param stageId stage number
		virtual std::vector<BrickDto> GetBrickSetup(int stageId) = 0; 
		/// get declared amount of stages
		virtual short GetTotalStagesCount() = 0; 
	};

}