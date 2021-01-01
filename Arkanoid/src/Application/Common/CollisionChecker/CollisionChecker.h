#pragma once
#include "../src/Application/Common/Enums/CollisionType.h"

namespace Arkanoid
{

	static class CollisionChecker
	{
	public:
#pragma region shape structs
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

		static CollisionType CheckCollision(Rectangle rect, Circle circle);
	};
}

