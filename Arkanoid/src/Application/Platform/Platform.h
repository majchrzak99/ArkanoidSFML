#pragma once
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid
{
	class Platform
	{
	private:
		float _posX;
		float _speed;
		float _width;
	public:
		Platform();
		float GetPosX();
		float GetWidth();
	};
}