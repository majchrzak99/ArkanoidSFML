#include "GameRenderer.h"

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
	void GameRenderer::drawBalls()
	{
	}
	GameRenderer::GameRenderer(sf::RenderWindow *window)
	{
		this->_window = window;
	}
	Renderer * GameRenderer::Render()
	{
		sf::Font font;

		if (!font.loadFromFile("assets/roboto_mono/roboto_mono.ttf"))
		{
			return this;
		}

		sf::Vector2<unsigned int> windowSize = this->_window->getSize();

		this->drawBricks(windowSize.x, windowSize.y);
		this->drawPlatform(windowSize.x, windowSize.y);
		this->drawBalls();
		return this;
	}
	void GameRenderer::PollEvents(sf::Event event)
	{
	}
}

