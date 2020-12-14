#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/MenuRenderer/MainMenu.h"
#include "../src/Ui/GameRenderer/GameRenderer.h"
#include "../src/Ui/Common/Renderer/Renderer.h"
namespace Arkanoid
{
	class MenuRenderer : public Renderer
	{
	private:
		int _selectionIndex;
		std::vector<MenuItem> _mainMenuItems;
		bool _selectionReady;
		std::vector<MenuItem> getMainMenuItems();
		void lowerSelection();
		void riseSelection();
		Renderer* applySelection();
	public:
		MenuRenderer(sf::RenderWindow* window);
		Renderer* Render();
		void PollEvents(sf::Event event);
	};

}
