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
		this->_platform = Platform(6.0f, this->MatrixWidth / 2.0f);
		this->_balls.push_back(Ball(0.5f, this->MatrixWidth / 2.0f, this->MatrixHeight - 2.0f));
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
		std::vector<BrickDto> readedBricks = this->_stageLoader->GetBrickSetup(stageId);

		for (auto it = readedBricks.begin(); it != readedBricks.end(); ++it) {
			Brick brick;
			brick.PosX = it->PosX * brick.Width;
			brick.PosY = it->PosY * brick.Height;
			brick.State = (BrickState)it->BrickStateId;
			this->_bricks.push_back(brick);
		}
	}
	void Game::CheckCollisions()
	{
	}
	void Game::MovePlatform()
	{
		if (this->_platform.MoveDirection == HorizontalMoveDirection::Left)
		{
			float position = this->_platform.GetPosX() - this->_platform.GetSpeed();
			if (position <= 0.0f) {
				this->_platform.Move(0.0f);
			}
			else {
				this->_platform.Move(position);
			}
		}
		else if (this->_platform.MoveDirection == HorizontalMoveDirection::Right)
		{
			float position = this->_platform.GetPosX() + this->_platform.GetSpeed();
			if (position >= this->MatrixWidth - this->_platform.GetWidth()) {
				this->_platform.Move(this->MatrixWidth - this->_platform.GetWidth());
			}
			else {
				this->_platform.Move(position);
			}
		}
	}
	void Game::MoveBalls()
	{
		std::vector<short> ballsToDelete;
		short id = 0;
		for (auto ball = this->_balls.begin(); ball != this->_balls.end(); ++ball) {
			float positionX = ball->GetPosX();
			float positionY = ball->GetPosY();

			if (ball->HorizontalDirection == HorizontalMoveDirection::Left)
			{
				positionX -= ball->GetHorizontalSpeed();
				if (positionX <= 0.0f) {
					positionX = 0.0f;
					ball->HorizontalDirection = HorizontalMoveDirection::Right;
				}
			}
			else if (ball->HorizontalDirection == HorizontalMoveDirection::Right)
			{
				positionX += ball->GetHorizontalSpeed();
				if (positionX + ball->GetRadius() >= this->MatrixWidth) {
					positionX = this->MatrixWidth - ball->GetRadius();
					ball->HorizontalDirection = HorizontalMoveDirection::Left;
				}
			}

			if (ball->VerticalDirection == VerticalMoveDirection::Down)
			{
				positionY += ball->GetVerticalSpeed();
				if (positionY + ball->GetRadius() >= this->MatrixHeight) {
					this->_lives--;
					ballsToDelete.push_back(id);
				}
			}
			else if (ball->VerticalDirection == VerticalMoveDirection::Up)
			{
				positionY -= ball->GetVerticalSpeed();
				if (positionY <= 0.0f) {
					positionY = 0.0f;
					ball->VerticalDirection = VerticalMoveDirection::Down;
				}
			}
			ball->Move(positionX, positionY);

			id++;
		}
		for (auto id : ballsToDelete) {
			this->_balls.erase(this->_balls.begin() + id);
		}
	}
	void Game::SetPlatformDirection(HorizontalMoveDirection direction)
	{
		this->_platform.MoveDirection = direction;
	}
	void Game::CalculateFrame()
	{
		this->MovePlatform();
		this->MoveBalls();


		this->CheckCollisions();
	}
}