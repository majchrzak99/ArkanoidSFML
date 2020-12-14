#include "MenuRenderer.h"

namespace Arkanoid {
	MenuRenderer::MenuRenderer(sf::RenderWindow* window)
	{
		this->_window = window;
	}
	Renderer* MenuRenderer::Render()
	{
		sf::Font font;

		if (!font.loadFromFile("assets/roboto_mono/roboto_mono.ttf"))
		{
			return this;
		}

		sf::Text text;
		text.setFont(font);
		text.setString("Testuje fonty");
		text.setFillColor(sf::Color::Black);
		this->_window->draw(text);
		return this;
	}
	void MenuRenderer::PollEvents(sf::Event event)
	{

	}

}
