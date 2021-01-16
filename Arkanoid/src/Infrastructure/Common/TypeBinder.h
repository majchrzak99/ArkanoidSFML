#pragma once
#include "../src/Application/Common/Abstractions/StageLoader.h"
#include "../src/Infrastructure/StageReader/StageReader.h"

namespace Arkanoid {
	/// class that binds interface implementation with declaration
	static class TypeBinder {
	public:
		/// binds stage loader
		static StageLoader* GetStageLoader();
	};
}