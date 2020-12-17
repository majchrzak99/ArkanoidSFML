#pragma once
#include <vector>
#include "../Ball/Ball.h"
#include "../Brick/Brick.h"
#include "../Platform/Platform.h"
#include "../src/Application/GameSettings/GameSettings.h"
#include "../src/Application/Common/Abstractions/StageLoader.h"
#include "../src/Infrastructure/Common/TypeBinder.h"
#include "../src/Application/Common/Enums/MoveDirection.h"

namespace Arkanoid
{
	class Game
	{
	private:
		std::vector<Ball> _balls;
		std::vector<Brick> _bricks;
		Platform _platform;
		short _lives;
		long _points;
		StageLoader* _stageLoader;
		void CheckCollisions();
		void MovePlatform();
		void MoveBalls();
	public:
		const float MatrixWidth = 24.0f;
		const float MatrixHeight = 10.0f;
		std::vector<Ball> GetBalls();
		std::vector<Brick> GetBricks();
		Platform GetPlatform();
		Game();
		~Game();
		void LoadStage(int stageId);
		void SetPlatformDirection(HorizontalMoveDirection direction);
		void CalculateFrame();
	};


}