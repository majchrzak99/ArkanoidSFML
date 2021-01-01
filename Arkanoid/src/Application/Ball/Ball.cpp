#include "Ball.h"

namespace Arkanoid {
	Ball::Ball()
	{
		this->_posX = 0.0f;
		this->_posY = 0.0f;
		this->_vSpeed = 0.20f;
		this->_hSpeed = 0.20f;
		this->_radius = 0.0f;
		this->CanChangeDirection = true;
		this->HorizontalDirection = HorizontalMoveDirection::Right;
		this->VerticalDirection = VerticalMoveDirection::Up;
	}
	Ball::Ball(float radius, float posX, float posY, float speed)
	{
		this->_posX = posX;
		this->_posY = posY;
		this->_vSpeed = speed;
		this->_hSpeed = speed;
		this->_radius = radius;
		this->CanChangeDirection = true;
		this->HorizontalDirection = HorizontalMoveDirection::Right;
		this->VerticalDirection = VerticalMoveDirection::Up;
	}
	void Ball::Move(float posX, float posY)
	{
		this->_posX = posX;
		this->_posY = posY;
	}

	float Ball::GetVerticalSpeed()
	{
		return this->_vSpeed;
	}

	float Ball::GetHorizontalSpeed()
	{
		return this->_hSpeed;
	}

	void Ball::SetVerticalSpeed(float speed)
	{
		this->_vSpeed = speed;
	}

	void Ball::SetHorizontalSpeed(float speed)
	{
		this->_hSpeed = speed;
	}

	float Ball::GetPosX()
	{
		return this->_posX;
	}

	float Ball::GetPosY()
	{
		return this->_posY;
	}

	float Ball::GetRadius()
	{
		return this->_radius;
	}

	void Ball::IncreaseSpeed()
	{
		this->_hSpeed += 0.002;
		this->_vSpeed += 0.001;
	}

}
