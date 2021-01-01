#include "MainWindow.h"
#include <iostream>
namespace Arkanoid
{

	Window::Window()
	{
		this->_window.create(sf::VideoMode(1280, 720), "Arkanoid", sf::Style::Default /*| sf::Style::Fullscreen*/);
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
				if (event.type == sf::Event::Resized)
				{
					sf::View view = this->_window.getDefaultView();
					view.setSize(event.size.width, event.size.height);
					view.reset(sf::FloatRect(0.0f, 0.0f, event.size.width, event.size.height));
					//view.setViewport(sf::FloatRect(0.0f, 0.0f, event.size.width, event.size.height));
					this->_window.setView(view);
				}

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