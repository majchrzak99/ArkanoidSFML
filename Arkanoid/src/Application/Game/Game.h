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
	///Game object
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
		const float MatrixWidth = 24.0f; ///Width of game space
		const float MatrixHeight = 10.0f;///Height of game space
		///balls getter
		std::vector<Ball> GetBalls(); 
		///brick getter
		std::vector<Brick> GetBricks(); 
		///state getter
		GameState GetState();
		///platform getter
		Platform GetPlatform();
		///default constructor
		Game();
		///default destructor
		~Game();
		///load stage bricks setup to game
		///param stageId stage number
		void LoadStage(int stageId);
		/// changes direction of platform
		/// param direction new direction of a platform
		void SetPlatformDirection(HorizontalMoveDirection direction);
		/// makes collision and other calculations on single step of game
		void CalculateFrame();
		/// gets ball moving, when any speed is equal 0
		void RunInactiveBalls();
		/// stops calculating frame
		void Pause();
		/// resume calculating frame
		void Resume();
		/// pints getter
		unsigned long GetPoints();
		/// lives getter
		int GetLives();
	};
}