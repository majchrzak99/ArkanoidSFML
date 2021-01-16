#pragma once
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid {
	/// Ball
	class Ball
	{
		float _posX; /// postion X
		float _posY; /// position y
		float _vSpeed; /// vertical speed
		float _hSpeed; /// horizontal speed
		float _radius; ///radius of a ball
	public:
		/// empty constructor,
		Ball();
		/// constructor with setup
		Ball(float radius, float posX, float posY, float speed); 
		bool CanChangeDirection; /// flag if ball can change moving direction
		///move ball to position
		void Move(float posX, float posY); 
		/// _vSpeed getter
		float GetVerticalSpeed(); 
		float GetHorizontalSpeed();/// _hSpeed getter
		///_vSpeed setter
		/// param speed new vertical speed of ball
		void SetVerticalSpeed(float speed);
		///_hSpeed setter
		/// param speed new horizontal speed of ball
		void SetHorizontalSpeed(float speed);
		/// _posX getter
		float GetPosX();
		/// _posY getter
		float GetPosY();
		/// _radius getter
		float GetRadius();
		/// increases speed by const values
		void IncreaseSpeed();
		HorizontalMoveDirection HorizontalDirection; /// horizontal move direction
		VerticalMoveDirection VerticalDirection;/// vertical move direction
	};
}


