#pragma once
namespace Arkanoid {
	///state of brick enum
	enum class BrickState {
		None = 0,
		Destroyed = 1,
		Cracked = 2,
		Solid = 3
	};
}