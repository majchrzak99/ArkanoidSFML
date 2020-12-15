#pragma once
#include "../src/Application/Brick/BrickState.h"
namespace Arkanoid
{
	class Brick
	{
	public:
		BrickState State;
		float PosX;
		float PosY;
		const float Width = 2.0f;
		const float Height = 1.0f;
	};
}