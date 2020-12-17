#pragma once
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid {
	class Ball
	{
		float _posX;
		float _posY;
		float _vSpeed;
		float _hSpeed;
		float _radius;
	public:
		Ball();
		Ball(float radius, float posX, float posY);
		void Move(float posX, float posY);
		float GetVerticalSpeed();
		float GetHorizontalSpeed();
		float GetPosX();
		float GetPosY();
		float GetRadius();
		HorizontalMoveDirection HorizontalDirection;
		VerticalMoveDirection VerticalDirection;
	};
}


