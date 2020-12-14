#pragma once
#include <string>
namespace Arkanoid {
	enum class MenuOption {
		NewGame = 0,
		LeaderBoard = 1,
		Options = 2,
		Exit = 3
	};

	struct MenuItem {
		std::string Text;
		MenuOption Option;
		int Id;
	};
}