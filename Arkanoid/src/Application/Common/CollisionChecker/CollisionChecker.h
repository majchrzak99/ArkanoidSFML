#pragma once
#include "../src/Application/Common/Enums/CollisionType.h"

namespace Arkanoid
{
	///Class used to check collision
	static class CollisionChecker
	{
	public:
#pragma region shape structs
		///describes single point on graph
		struct Point
		{
			float X;
			float Y;

			Point() {
				X = 0.0f;
				Y = 0.0f;
			};
			Point(float x, float y) {
				X = x;
				Y = y;
			}

		};
		///describes rectangle on graph using points
		struct Rectangle
		{
			Point LeftBottom;
			Point RightTop;

			Rectangle(Point leftBottom, Point rightTop)
			{
				LeftBottom = leftBottom;
				RightTop = rightTop;
			}
		};
		///describes circle on graph
		struct Circle
		{
			Point Center;
			float Radius;
			Circle(Point center, float radius)
			{
				Center = center;
				Radius = radius;
			}
		};
#pragma endregion
		///Check if rectangle collide with circle
		///param rect rectangle cords
		///param circle rectangle cords
		static CollisionType CheckCollision(Rectangle rect, Circle circle);
	};
}

