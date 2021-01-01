#pragma once
#include "../src/Application/Brick/BrickState.h"
namespace Arkanoid
{
	class Brick
	{
		float _width = 2.0f;
		float _height = 1.0f;
	public:
		BrickState State;
		float PosX;
		float PosY;
		float GetWidth();
		float GetHeight();
	};
}