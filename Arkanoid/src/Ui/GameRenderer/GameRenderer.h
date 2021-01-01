#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/Common/Renderer/Renderer.h"
#include "../src/Ui/MenuRenderer/MenuRenderer.h"
#include "../src/Application/Game/Game.h"
namespace Arkanoid
{
	class GameRenderer : public Renderer
	{
	private:
		Game _game;
		bool _canReturnToMenu;
		void drawBricks(sf::Vector2<unsigned int>size, sf::Vector2<float>position);
		void drawPlatform(sf::Vector2<unsigned int>size, sf::Vector2<float>position);
		void drawBalls(sf::Vector2<unsigned int>size, sf::Vector2<float>position);
		void drawInfo(sf::Vector2<unsigned int>size, sf::Vector2<float>position);
	public:
		GameRenderer(sf::RenderWindow* window);
		Renderer* Render();
		void PollEvents(sf::Event event);
	};
}

