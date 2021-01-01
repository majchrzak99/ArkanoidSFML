#include "Game.h"
//#include <iostream>

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
	GameState Game::GetState()
	{
		return this->_state;
	}
	Platform Game::GetPlatform()
	{
		return this->_platform;
	}
	Game::Game()
	{
		this->_platform = Platform(6.0f, 0.5f, this->MatrixWidth / 2.0f, this->MatrixHeight - 1.5f);
		this->_balls.push_back(Ball(0.3f, this->MatrixWidth / 2.0f, this->MatrixHeight - 2.5f, 0.0f));
		this->_lives = 3;
		this->_points = 0;
		this->_stageNumber = 1;
		this->_state = GameState::Active;
		this->_stageLoader = TypeBinder::GetStageLoader();

		this->_stageCount = this->_stageLoader->GetTotalStagesCount();
		this->LoadStage(this->_stageNumber);
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
			brick.PosX = it->PosX * brick.GetWidth();
			brick.PosY = it->PosY * brick.GetHeight();
			brick.State = (BrickState)it->BrickStateId;

			if (brick.State != BrickState::None)
				this->_bricks.push_back(brick);
		}
	}
	void Game::CheckCollisions()
	{
		for (auto ball = this->_balls.begin(); ball != this->_balls.end(); ++ball)
		{
			CollisionChecker::Circle cBall(CollisionChecker::Point(ball->GetPosX(), ball->GetPosY()), ball->GetRadius());

			//platform <> ball
			CollisionChecker::Rectangle cPlatform(
				CollisionChecker::Point(this->_platform.GetPosX(), this->_platform.GetPosY()),
				CollisionChecker::Point(this->_platform.GetPosX() + this->_platform.GetWidth(), this->_platform.GetPosY() + this->_platform.GetHeight())
			);

			CollisionType ballPlatformResult = CollisionChecker::CheckCollision(cPlatform, cBall);
			if (ballPlatformResult == CollisionType::None) {
				ball->CanChangeDirection = true;
			}
			else {
				this->ChangeBallDirectionsByCollision(&(*ball), ballPlatformResult);
			}

			//bricks <> ball
			std::vector<short> bricksToDelete;
			short id = 0;
			for (auto brick = this->_bricks.begin(); brick != this->_bricks.end(); ++brick)
			{
				CollisionChecker::Rectangle cBrick(
					CollisionChecker::Point(brick->PosX, brick->PosY),
					CollisionChecker::Point(brick->PosX + brick->GetWidth(), brick->PosY + brick->GetHeight())
				);
				CollisionType ballBrickResult = CollisionChecker::CheckCollision(cBrick, cBall);

				if (ballBrickResult != CollisionType::None) {
					this->ChangeBallDirectionsByCollision(&(*ball), ballBrickResult);
					bricksToDelete.push_back(id);
				}
				id++;
			}
			for (auto id : bricksToDelete) {
				//increase ball speed
				ball->IncreaseSpeed();
				this->_bricks.erase(this->_bricks.begin() + id);
				this->_points += BLOCK_DESTROYED_POINTS;
			}
		}

		//if there is no bricks left, render next stage
		if (this->_bricks.size() == 0) {
			this->_points += STAGE_COMPLETED_POINTS;

			if (this->_stageNumber == this->_stageCount)
			{
				this->_state = GameState::Win;
			}
			else
			{
				this->_stageNumber++;
				this->LoadStage(this->_stageNumber);
				this->_balls.clear();
				this->_balls.push_back(Ball(0.3f, this->MatrixWidth / 2.0f, this->MatrixHeight - 2.5f, 0.0f));
			}

		}
	}

	void Game::ChangeBallDirectionsByCollision(Ball* ball, CollisionType type)
	{
		if (ball->CanChangeDirection) {
			if (type == CollisionType::Corner)
			{
				if (ball->VerticalDirection == VerticalMoveDirection::Up)
				{
					ball->VerticalDirection = VerticalMoveDirection::Down;
				}
				else if (ball->VerticalDirection == VerticalMoveDirection::Down)
				{
					ball->VerticalDirection = VerticalMoveDirection::Up;
				}

				if (ball->HorizontalDirection == HorizontalMoveDirection::Left)
				{
					ball->HorizontalDirection = HorizontalMoveDirection::Right;
				}
				else if (ball->HorizontalDirection == HorizontalMoveDirection::Right)
				{
					ball->HorizontalDirection = HorizontalMoveDirection::Left;
				}

			}
			else if (type == CollisionType::Straight)
			{
				if (ball->VerticalDirection == VerticalMoveDirection::Up)
				{
					ball->VerticalDirection = VerticalMoveDirection::Down;
				}
				else if (ball->VerticalDirection == VerticalMoveDirection::Down)
				{
					ball->VerticalDirection = VerticalMoveDirection::Up;
				}
			}
		}
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
				if (positionX - ball->GetRadius() <= 0.0f) {
					positionX = ball->GetRadius();
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
				if (positionY - ball->GetRadius() <= 0.0f) {
					positionY = ball->GetRadius();
					ball->VerticalDirection = VerticalMoveDirection::Down;
				}
			}
			ball->Move(positionX, positionY);

			id++;
		}
		for (auto id : ballsToDelete) {
			this->_balls.erase(this->_balls.begin() + id);
		}

		//if still has lives but there is no ball in game
		if (this->_balls.size() == 0 && this->_lives > 0) {
			this->_balls.push_back(Ball(0.3f, this->MatrixWidth / 2.0f, this->MatrixHeight - 2.3f, 0.0f));
		}
	}
	void Game::SetPlatformDirection(HorizontalMoveDirection direction)
	{
		this->_platform.MoveDirection = direction;
	}
	void Game::CalculateFrame()
	{
		if (this->_state == GameState::Active) {
			this->MovePlatform();
			this->MoveBalls();

			if (this->_balls.size() == 0) {
				this->_state = GameState::GameOver;
				return;
			}
			this->CheckCollisions();
		}

	}
	void Game::RunInactiveBalls()
	{
		for (auto ball = this->_balls.begin(); ball != this->_balls.end(); ++ball) {
			if (ball->GetHorizontalSpeed() == 0.0f)
				ball->SetHorizontalSpeed(0.1f);
			if (ball->GetVerticalSpeed() == 0.0f)
				ball->SetVerticalSpeed(0.1f);
		}
	}
	void Game::Pause()
	{
		this->_state = GameState::Paused;
	}
	void Game::Resume()
	{
		this->_state = GameState::Active;
	}
	unsigned long Game::GetPoints()
	{
		return this->_points;
	}
	int Game::GetLives()
	{
		return this->_lives;
	}
}