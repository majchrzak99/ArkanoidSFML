#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <string>
#include "../src/Ui/GameRenderer/GameRenderer.h"
#include "../src/Ui/Common/Renderer/Renderer.h"
#include "../src/Ui/MenuRenderer/MenuRenderer.h"
#include "../src/Ui/GameSettingsRenderer/GameSettingsRenderer.h"

namespace Arkanoid
{
	class Window
	{
	private:
		sf::RenderWindow _window;
		Renderer* _renderer;


		int setBackground(std::string bgPath);
	public:
		Window();
		~Window();
		void Run();
	};
}
