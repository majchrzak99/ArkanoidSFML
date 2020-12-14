#include "MenuRenderer.h"

namespace Arkanoid {
	std::vector<MenuItem> MenuRenderer::getMainMenuItems()
	{
		std::vector<MenuItem> items;

		MenuItem item;

		item.Option = MenuOption::NewGame;
		item.Id = 1;
		item.Text = "Nowa Gra";
		items.push_back(item);

		item.Option = MenuOption::LeaderBoard;
		item.Id = 2;
		item.Text = "Tablica wyników";
		items.push_back(item);

		item.Option = MenuOption::Options;
		item.Id = 3;
		item.Text = "Opcje";
		items.push_back(item);

		item.Option = MenuOption::Exit;
		item.Id = 4;
		item.Text = "Wyjscie";
		items.push_back(item);

		return items;
	}
	MenuRenderer::MenuRenderer(sf::RenderWindow* window)
	{
		this->_window = window;
		this->_selectionIndex = 1;
		this->_selectionReady = false;
		this->_mainMenuItems = getMainMenuItems();

		std::sort(this->_mainMenuItems.begin(), this->_mainMenuItems.end(), [](MenuItem a, MenuItem b) {return a.Id < b.Id; });
	}
	Renderer* MenuRenderer::Render()
	{
		sf::Font font;

		if (!font.loadFromFile("assets/roboto_mono/roboto_mono.ttf"))
		{
			return this;
		}

		sf::Vector2<unsigned int> windowSize = this->_window->getSize();

		for (auto it = this->_mainMenuItems.begin(); it != this->_mainMenuItems.end(); ++it) {
			sf::Text text;
			text.setFont(font);
			text.setFillColor(sf::Color::White);
			text.setCharacterSize(25);

			if (it->Id == this->_selectionIndex) {
				text.setString("> " + it->Text);
			}
			else {
				text.setString(it->Text);
			}

			float yPos = windowSize.y / 2.0; //menu starting position
			yPos += it->Id * 40; //Menu index * line height
			text.setPosition(sf::Vector2f(windowSize.x / 4, yPos));

			this->_window->draw(text);
		}

		if (this->_selectionReady) {
			Renderer* nextRenderer = nullptr;
			nextRenderer = applySelection();
			delete this;
			return nextRenderer;
		}

		return this;
	}
	void MenuRenderer::PollEvents(sf::Event event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			this->_window->close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
		{
			this->lowerSelection();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
		{
			this->riseSelection();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
			this->_selectionReady = true;
		}
	}

	void MenuRenderer::lowerSelection()
	{
		this->_selectionIndex--;

		if (this->_selectionIndex < 1)
			this->_selectionIndex = 1;
	}
	void MenuRenderer::riseSelection()
	{
		this->_selectionIndex++;

		if (this->_selectionIndex > this->_mainMenuItems.back().Id)
			this->_selectionIndex = this->_mainMenuItems.back().Id;
	}
	Renderer * MenuRenderer::applySelection()
	{
		MenuOption selectedOption;

		for (auto item : this->_mainMenuItems) {
			if (item.Id == this->_selectionIndex) {
				selectedOption = item.Option;
			}
		}
		switch (selectedOption)
		{
		case MenuOption::NewGame: {
			return new GameRenderer(this->_window);
		}
		default:
			return this;
		}
	}
}
