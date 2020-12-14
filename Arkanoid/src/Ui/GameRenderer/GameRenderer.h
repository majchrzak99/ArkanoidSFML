#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/Common/Renderer/Renderer.h"
namespace Arkanoid
{
	class GameRenderer : public Renderer
	{
	public:
		GameRenderer(sf::RenderWindow* window);
		Renderer* Render();
		void PollEvents(sf::Event event);
	};
}

