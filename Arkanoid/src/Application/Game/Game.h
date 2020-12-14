#pragma once
#include <vector>
#include "../Ball/Ball.h"
#include "../Brick/Brick.h"
#include "../Platform/Platform.h"
namespace Arkanoid
{
	class Game
	{
	private:
		std::vector<Ball> balls;
		std::vector<Brick> bricks;
		Platform platform;
	public:

	};


}