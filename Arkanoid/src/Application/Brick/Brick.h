#pragma once
#include "../src/Application/Brick/BrickState.h"
namespace Arkanoid
{
	class Brick
	{
		float _width = 2.0f;
		float _height = 1.0f;
	public:
		BrickState State; /// brick state - solid, cracked etc.
		float PosX; /// posX
		float PosY; /// posY
		///width getter
		float GetWidth(); 
		///heigth getter
		float GetHeight(); 
	};
}