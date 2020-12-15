#include "Game.h"
namespace Arkanoid 
{
	std::vector<Ball> Game::GetBalls()
	{
		return this->_balls;
	}
	std::vector<Brick> Game::GetBricks()
	{
		return this->_bricks;
	}
	Platform Game::GetPlatform()
	{
		return this->_platform;
	}
	Game::Game()
	{
		this->_lives = 3;
		this->_points = 0;
		this->_stageLoader = TypeBinder::GetStageLoader();
		this->LoadStage(1);
	}

	Game::~Game()
	{
		delete this->_stageLoader;
	}

	void Game::LoadStage(int stageId)
	{
		 std::vector<BrickDto> readedBricks =  this->_stageLoader->GetBrickSetup(stageId);

		 for (auto it = readedBricks.begin(); it != readedBricks.end(); ++it) {
			 Brick brick;
			 brick.PosX = it->PosX * brick.Width;
			 brick.PosY = it->PosY * brick.Height;
			 brick.State = (BrickState)it->BrickStateId;
			 this->_bricks.push_back(brick);
		 }
	}
	void Game::DoCollisions()
	{
	}
}