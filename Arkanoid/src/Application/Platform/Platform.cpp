#include "Platform.h"
namespace Arkanoid {
	Platform::Platform()
	{
		this->_width = 6.0f;
		this->_posX = 11.0f;
	}
	float Platform::GetPosX()
	{
		return this->_posX;
	}
	float Platform::GetWidth()
	{
		return this->_width;
	}
}


