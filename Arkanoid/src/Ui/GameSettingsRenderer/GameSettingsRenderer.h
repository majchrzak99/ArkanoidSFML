#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../src/Ui/Common/Renderer/Renderer.h"
namespace Arkanoid
{
	class GameSettingsRenderer : public Renderer
	{
	public:
		Renderer * Render();
		void PollEvents(sf::Event event);
	};
}
