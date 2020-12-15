#pragma once
#include "../src/Application/Common/Abstractions/StageLoader.h"
#include "../src/Infrastructure/StageReader/StageReader.h"

namespace Arkanoid {
	static class TypeBinder {
	public:
		static StageLoader* GetStageLoader();
	};
}