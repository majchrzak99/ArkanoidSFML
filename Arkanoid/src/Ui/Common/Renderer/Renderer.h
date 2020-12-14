#pragma once
//#include "../src/Ui/Common/Enums/RendererState.h"
#include <SFML/Window.hpp>

namespace Arkanoid {
	class Renderer {
	public:
		virtual Renderer* Render() = 0;
		virtual void PollEvents(sf::Event event) = 0;
	};
}