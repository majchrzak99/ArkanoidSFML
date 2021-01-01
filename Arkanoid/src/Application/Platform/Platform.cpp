#include "Platform.h"
namespace Arkanoid {
	Platform::Platform()
	{
		this->_width = 0.0f;
		this->_height = 0.0f;
		this->_posX = 0.0f;
		this->_posY = 0.0f;
		this->_speed = 0.25f;
	}
	Platform::Platform(float width,float height, float positionX,float positionY)
	{
		this->_width = width;
		this->_height = height;
		this->_posX = positionX;
		this->_posY = positionY;
		this->_speed = 0.25f;
	}
	float Platform::GetPosX()
	{
		return this->_posX;
	}
	float Platform::GetPosY()
	{
		return this->_posY;
	}
	float Platform::GetWidth()
	{
		return this->_width;
	}
	float Platform::GetHeight()
	{
		return this->_height;
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


