#pragma once
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid
{
	/// Describes platform behavior
	class Platform
	{
	private:
		float _posX;
		float _posY;
		float _speed;
		float _width;
		float _height;
	public:
		///default constructor
		Platform();
		/// constructor with basic setup
		Platform(float width, float height, float positionX, float positionY);
		/// x position getter
		float GetPosX();
		/// y position getter
		float GetPosY();
		/// width getter 
		float GetWidth();
		///height getter
		float GetHeight();
		/// speed getter
		float GetSpeed();
		/// move platform to position
		void Move(float posX);
		/// platform move direction
		HorizontalMoveDirection MoveDirection;
	};
}