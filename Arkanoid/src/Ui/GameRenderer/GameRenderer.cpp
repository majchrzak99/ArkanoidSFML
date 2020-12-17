#include "GameRenderer.h"

#include <iostream>

namespace Arkanoid {
	void GameRenderer::drawBricks(float maxWidth, float maxHeight)
	{
		std::vector<Brick> bricks = this->_game.GetBricks();
		float scaleX = maxWidth / this->_game.MatrixWidth;
		float scaleY = maxHeight / this->_game.MatrixHeight;

		for (auto it = bricks.begin(); it != bricks.end(); ++it) {

			float brickPosX = it->PosX * scaleX;
			float brickPosY = it->PosY * scaleY;

			float brickWidth = it->Width * scaleX;
			float brickHeight = it->Height * scaleY;


			sf::RectangleShape rectangle(sf::Vector2<float>(brickWidth, brickHeight));
			rectangle.setFillColor(sf::Color::Red);
			rectangle.setOutlineThickness(2.0f);
			rectangle.setOutlineColor(sf::Color::Black);
			rectangle.setPosition(brickPosX, brickPosY);

			this->_window->draw(rectangle);
		}
	}

	void GameRenderer::drawPlatform(float maxWidth, float maxHeight)
	{
		float scaleX = maxWidth / this->_game.MatrixWidth;
		Platform platform = this->_game.GetPlatform();

		float posX = platform.GetPosX() * scaleX;
		float posY = maxHeight - 100.0f;

		float width = platform.GetWidth() * scaleX;
		float height = 50.0f;

		sf::RectangleShape rectangle(sf::Vector2<float>(width, height));
		rectangle.setPosition(posX, posY);
		this->_window->draw(rectangle);
	}

	void GameRenderer::drawBalls(float maxWidth, float maxHeight)
	{
		float scaleX = maxWidth / this->_game.MatrixWidth;
		float scaleY = maxHeight / this->_game.MatrixHeight;

		std::vector<Ball> balls = this->_game.GetBalls();
		for (auto ball : balls) {
			float ballPosX = ball.GetPosX() * scaleX;
			float ballPosY = ball.GetPosY() * scaleY;

			float ballRadius = ball.GetRadius() * scaleX;

			sf::CircleShape circle(ballRadius, 64);
			circle.setPosition(ballPosX, ballPosY);
			circle.setFillColor(sf::Color::Blue);
			std::cout << "x:" << ballPosX << " y: " << ballPosY << std::endl;
			this->_window->draw(circle);
		}
	}

	GameRenderer::GameRenderer(sf::RenderWindow *window)
	{
		this->_window = window;
	}

	Renderer* GameRenderer::Render()
	{
		sf::Thread thread(&Game::CalculateFrame, &(this->_game));
		thread.launch();

		sf::Vector2<unsigned int> windowSize = this->_window->getSize();

		this->drawBricks(windowSize.x, windowSize.y);
		this->drawPlatform(windowSize.x, windowSize.y);
		this->drawBalls(windowSize.x, windowSize.y);
		return this;
	}
	void GameRenderer::PollEvents(sf::Event event)
	{
		if (event.type == sf::Event::EventType::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				this->_game.SetPlatformDirection(HorizontalMoveDirection::Left);
				break;
			case sf::Keyboard::Right:
				this->_game.SetPlatformDirection(HorizontalMoveDirection::Right);
				break;
			default:
				this->_game.SetPlatformDirection(HorizontalMoveDirection::None);
				break;
			}
		}
		if (event.type == sf::Event::EventType::KeyReleased) {

			if (event.key.code == sf::Keyboard::Left && this->_game.GetPlatform().MoveDirection == HorizontalMoveDirection::Left) {
				this->_game.SetPlatformDirection(HorizontalMoveDirection::None);
			}
			if (event.key.code == sf::Keyboard::Right && this->_game.GetPlatform().MoveDirection == HorizontalMoveDirection::Right) {
				this->_game.SetPlatformDirection(HorizontalMoveDirection::None);
			}
		}
	}
}

