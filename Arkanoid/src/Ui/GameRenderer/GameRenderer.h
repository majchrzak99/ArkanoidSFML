#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/Common/Renderer/Renderer.h"
#include "../src/Application/Game/Game.h"
namespace Arkanoid
{
	class GameRenderer : public Renderer
	{
	private:
		Game _game;
		void drawBricks(float maxWidth, float maxHeight);
		void drawPlatform(float maxWidth, float maxHeight);
		void drawBalls();
	public:
		GameRenderer(sf::RenderWindow* window);
		Renderer* Render();
		void PollEvents(sf::Event event);
	};
}

