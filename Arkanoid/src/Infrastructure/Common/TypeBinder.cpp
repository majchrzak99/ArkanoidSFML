
#pragma once
#include "TypeBinder.h"

namespace Arkanoid {
	StageLoader* TypeBinder::GetStageLoader() {
		return new StageReader();
	};
}

