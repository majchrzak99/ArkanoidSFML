#pragma once

namespace Arkanoid 
{
	///Describees direction that collision came from
	enum class CollisionType {
		None = 0,
		Straight = 1,
		Corner = 2
	};
}