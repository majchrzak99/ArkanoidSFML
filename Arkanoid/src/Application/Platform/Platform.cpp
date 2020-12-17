#include "Platform.h"
namespace Arkanoid {
	Platform::Platform()
	{
		this->_width = 0.0f;
		this->_posX = 0.0f;
		this->_speed = 0.25f;
	}
	Platform::Platform(float width, float position)
	{
		this->_width = width;
		this->_posX = position;
		this->_speed = 0.25f;
	}
	float Platform::GetPosX()
	{
		return this->_posX;
	}
	float Platform::GetWidth()
	{
		return this->_width;
	}
	float Platform::GetSpeed()
	{
		return this->_speed;
	}
	void Platform::Move(float posX)
	{
		this->_posX = posX;
	}
}


