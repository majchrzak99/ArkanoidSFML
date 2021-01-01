#pragma once
#include <vector>
#include "../Ball/Ball.h"
#include "../Brick/Brick.h"
#include "../Platform/Platform.h"
#include "../src/Application/GameSettings/GameSettings.h"
#include "../src/Application/Common/Abstractions/StageLoader.h"
#include "../src/Infrastructure/Common/TypeBinder.h"
#include "../src/Application/Common/Enums/MoveDirection.h"
#include "../src/Application/Common/Enums/GameState.h"
#include "../src/Application/Common/CollisionChecker/CollisionChecker.h"

#define BLOCK_DESTROYED_POINTS 25;
#define STAGE_COMPLETED_POINTS 100;

namespace Arkanoid
{
	class Game
	{
	private:
		std::vector<Ball> _balls;
		std::vector<Brick> _bricks;
		Platform _platform;
		short _lives;
		unsigned long  _points;
		StageLoader* _stageLoader;
		GameState _state;
		short _stageNumber;
		short _stageCount;
		void CheckCollisions();
		void MovePlatform();
		void MoveBalls();
		void ChangeBallDirectionsByCollision(Ball* ball, CollisionType type);
	public:
		const float MatrixWidth = 24.0f;
		const float MatrixHeight = 10.0f;
		std::vector<Ball> GetBalls();
		std::vector<Brick> GetBricks();
		GameState GetState();
		Platform GetPlatform();
		Game();
		~Game();
		void LoadStage(int stageId);
		void SetPlatformDirection(HorizontalMoveDirection direction);
		void CalculateFrame();
		void RunInactiveBalls();
		void Pause();
		void Resume();
		unsigned long GetPoints();
		int GetLives();
	};
}