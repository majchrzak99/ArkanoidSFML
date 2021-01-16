#include "GameRenderer.h"
#include <iostream>
namespace Arkanoid {
	void GameRenderer::drawBricks(sf::Vector2<unsigned int>size, sf::Vector2<float>position)
	{
		std::vector<Brick> bricks = this->_game.GetBricks();
		float scaleX = size.x / this->_game.MatrixWidth;
		float scaleY = size.y / this->_game.MatrixHeight;

		for (auto it = bricks.begin(); it != bricks.end(); ++it) {

			float brickPosX = position.x + it->PosX * scaleX;
			float brickPosY = position.y + it->PosY * scaleY;

			float brickWidth = it->GetWidth() * scaleX;
			float brickHeight = it->GetHeight() * scaleY;


			sf::RectangleShape rectangle(sf::Vector2<float>(brickWidth, brickHeight));
			rectangle.setFillColor(sf::Color::Red);
			/*rectangle.setOutlineThickness(2.0f);
			rectangle.setOutlineColor(sf::Color::Black);*/
			rectangle.setPosition(brickPosX, brickPosY);

			this->_window->draw(rectangle);
		}
	}

	void GameRenderer::drawPlatform(sf::Vector2<unsigned int>size, sf::Vector2<float>position)
	{
		float scaleX = size.x / this->_game.MatrixWidth;
		float scaleY = size.y / this->_game.MatrixHeight;

		Platform platform = this->_game.GetPlatform();

		float posX = position.x + platform.GetPosX() * scaleX;
		float posY = position.y + platform.GetPosY() * scaleY;

		float width = platform.GetWidth() * scaleX;
		float height = platform.GetHeight() * scaleY;

		sf::RectangleShape rectangle(sf::Vector2<float>(width, height));
		rectangle.setPosition(posX, posY);
		this->_window->draw(rectangle);
	}

	void GameRenderer::drawBalls(sf::Vector2<unsigned int>size, sf::Vector2<float>position)
	{
		float scaleX = size.x / this->_game.MatrixWidth;
		float scaleY = size.y / this->_game.MatrixHeight;

		std::vector<Ball> balls = this->_game.GetBalls();
		for (auto ball : balls) {
			float ballPosX = position.x + (ball.GetPosX() - ball.GetRadius()) * scaleX;
			float ballPosY = position.y + (ball.GetPosY() - ball.GetRadius()) * scaleY;

			float ballRadius = ball.GetRadius() * scaleY;

			sf::CircleShape circle(ballRadius, 64);
			circle.setPosition(ballPosX, ballPosY);
			circle.setFillColor(sf::Color::Blue);
			this->_window->draw(circle);
		}
	}

	void GameRenderer::drawInfo(sf::Vector2<unsigned int> size, sf::Vector2<float> position)
	{
		sf::Font font;

		if (!font.loadFromFile("assets/roboto_mono/roboto_mono.ttf"))
		{
			std::cout << "Cannot load font" << std::endl;
		}

		sf::Vector2<unsigned int> windowSize = this->_window->getSize();

		sf::Text lifes;
		lifes.setFont(font);
		lifes.setFillColor(sf::Color::White);
		lifes.setCharacterSize(25);

		lifes.setPosition(position);
		lifes.setString("Zycia: " + std::to_string(this->_game.GetLives()));

		sf::Text points;
		points.setFont(font);
		points.setFillColor(sf::Color::White);
		points.setCharacterSize(25);

		points.setPosition(sf::Vector2<float>(position.x,position.y + 40));
		points.setString("Punkty: " + std::to_string(this->_game.GetPoints()));

		sf::RectangleShape line(sf::Vector2<float>(5.0f,size.y));
		line.setPosition(size.x - 5.0f, position.y);
		line.setFillColor(sf::Color::Black);

		this->_window->draw(lifes);
		this->_window->draw(points);
		this->_window->draw(line);
	}

	GameRenderer::GameRenderer(sf::RenderWindow *window)
	{
		this->_window = window;
		this->_canReturnToMenu = false;
	}

	Renderer* GameRenderer::Render()
	{
		sf::Thread thread(&Game::CalculateFrame, &(this->_game));
		thread.launch();
		sf::Vector2<unsigned int> windowSize = this->_window->getSize();
		sf::Vector2<unsigned int> gameSize = sf::Vector2<unsigned int>(windowSize.x *0.85, windowSize.y);
		sf::Vector2<unsigned int> infoSize = sf::Vector2<unsigned int>(windowSize.x *0.15, windowSize.y);

		sf::Vector2<float> infoPosition = sf::Vector2<float>(0, 0);
		sf::Vector2<float> gamePosition = sf::Vector2<float>(infoSize.x, 0);

		if (this->_game.GetState() == GameState::Active || this->_game.GetState() == GameState::Paused) {
			this->drawBricks(gameSize, gamePosition);
			this->drawPlatform(gameSize, gamePosition);
			this->drawBalls(gameSize, gamePosition);
			this->drawInfo(infoSize, infoPosition);
		}

		if (this->_canReturnToMenu)
		{
			if (this->_game.GetState() == GameState::GameOver || this->_game.GetState() == GameState::Paused)
			{
				Renderer* nextRenderer = new MenuRenderer(this->_window);
				delete this;
				return nextRenderer;
			}
		}
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
			case sf::Keyboard::Space:
				if (this->_game.GetState() == GameState::Paused)
				{
					this->_game.Resume();
				}
				else if (this->_game.GetState() == GameState::Active)
				{
					this->_game.RunInactiveBalls();

				}
				break;
			case sf::Keyboard::Escape:
				if (this->_game.GetState() == GameState::Active) {
					this->_game.Pause();
				}
				else if (this->_game.GetState() == GameState::Paused) {
					this->_canReturnToMenu = true;
				}
				else if (this->_game.GetState() == GameState::GameOver) {
					this->_canReturnToMenu = true;
				}
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

