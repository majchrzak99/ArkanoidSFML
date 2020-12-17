#include "MainWindow.h"
#include <iostream>
namespace Arkanoid
{

	Window::Window()
	{
		this->_window.create(sf::VideoMode(1920, 1080), "Arkanoid", sf::Style::Default /*| sf::Style::Fullscreen*/);
		this->_window.setVerticalSyncEnabled(true);

		this->_renderer = new MenuRenderer(&(this->_window));
		//this->_renderThread = new sf::Thread(this->_renderer->Render(),this->_renderer);
	}

	Window::~Window() {
		delete this->_renderer;
	}
	/**
		Main loop of application
		Handles events and render fames
	*/
	void Window::Run()
	{
		while (this->_window.isOpen())
		{
			sf::Event event;
			while (this->_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->_window.close();

				this->_renderer->PollEvents(event);
			}
	
			this->setBackground("assets/background.jpg");
			this->_renderer = this->_renderer->Render();

			this->_window.display();
		}
	}
	/**
		Sets background image to window
		bgPath: relative path to background image
	*/
	int Window::setBackground(std::string bgPath)
	{
		sf::Texture texture;
		texture.loadFromFile(bgPath);
		texture.setSmooth(true);

		sf::Sprite background(texture);


		background.setScale(
			(float)this->_window.getSize().x / background.getLocalBounds().width,
			(float)this->_window.getSize().y / background.getLocalBounds().height
		);
		this->_window.draw(background);

		return 0;
	}
}