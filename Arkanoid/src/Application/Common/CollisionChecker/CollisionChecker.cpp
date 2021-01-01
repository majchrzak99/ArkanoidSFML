#include "CollisionChecker.h"
namespace Arkanoid {
	CollisionType CollisionChecker::CheckCollision(Rectangle rect, Circle circle)
	{
		//check if ball is outside of platform in x and y axis
		bool outsideX = circle.Center.X + circle.Radius < rect.LeftBottom.X || circle.Center.X - circle.Radius > rect.RightTop.X;
		bool outsideY = circle.Center.Y + circle.Radius < rect.LeftBottom.Y || circle.Center.Y - circle.Radius > rect.RightTop.Y;

		float distX = circle.Center.X + circle.Radius <= rect.LeftBottom.X
			? rect.LeftBottom.X - circle.Center.X - circle.Radius
			: circle.Center.X - circle.Radius - rect.RightTop.X;

		float distY = circle.Center.Y + circle.Radius <= rect.LeftBottom.Y
			? rect.LeftBottom.Y - circle.Center.Y - circle.Radius
			: circle.Center.Y - circle.Radius - rect.RightTop.Y;


		if (outsideX && outsideY)
		{
			//find nearest point to circle in rectangle (circle at any of corners in rectangle)


			bool isCollided = distX * distX + distY * distY <= circle.Radius * circle.Radius;

			if (isCollided)
				return CollisionType::Corner;
		}
		else
		{
			//treat circle as a rectangle and detect collision of two rectangles
			if (distX < 0.0f && distY  <= 0.0f)
				return CollisionType::Straight;
		}
		return CollisionType::None;
	}
}
