#pragma once
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid
{
	class Platform
	{
	private:
		float _posX;
		float _posY;
		float _speed;
		float _width;
		float _height;
	public:
		Platform();
		Platform(float width, float height, float positionX, float positionY);
		float GetPosX();
		float GetPosY();
		float GetWidth();
		float GetHeight();
		float GetSpeed();
		void Move(float posX);
		HorizontalMoveDirection MoveDirection;
	};
}