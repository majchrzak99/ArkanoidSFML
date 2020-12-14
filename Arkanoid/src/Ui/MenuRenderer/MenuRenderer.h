#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/Common/Renderer/Renderer.h"
namespace Arkanoid
{
	class MenuRenderer : public Renderer
	{
	private:
		sf::RenderWindow* _window;

	public:
		MenuRenderer(sf::RenderWindow* window);
		Renderer* Render();
		void PollEvents(sf::Event event);
	};

}
