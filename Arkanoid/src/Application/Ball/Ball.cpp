#include "Ball.h"

namespace Arkanoid {
	Ball::Ball()
	{
		this->_posX = 0.0f;
		this->_posY = 0.0f;
		this->_vSpeed = 0.20f;
		this->_hSpeed = 0.20f;
		this->_radius = 0.0f;
		this->HorizontalDirection = HorizontalMoveDirection::Right;
		this->VerticalDirection = VerticalMoveDirection::Up;
	}
	Ball::Ball(float radius, float posX, float posY)
	{
		this->_posX = posX;
		this->_posY = posY;
		this->_vSpeed = 0.20f;
		this->_hSpeed = 0.20f;
		this->_radius = radius;
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

}
