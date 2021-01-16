#pragma once
namespace Arkanoid
{
	///describes a state of game
	enum class GameState
	{
		None = 0,
		Active = 1,
		Paused = 2,
		GameOver = 3,
		Win = 4
	};
}
