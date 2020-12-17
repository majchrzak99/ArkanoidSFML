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
		Platform(float width, float position);
		float GetPosX();
		float GetWidth();
		float GetSpeed();
		void Move( float posX);
		HorizontalMoveDirection MoveDirection;
	};
}