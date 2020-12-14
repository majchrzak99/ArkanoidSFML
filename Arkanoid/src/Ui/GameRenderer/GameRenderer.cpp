#include "GameRenderer.h"

namespace Arkanoid {
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
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(25);
		text.setString("TEST");
		this->_window->draw(text);
		return this;
	}
	void GameRenderer::PollEvents(sf::Event event)
	{
	}
}

