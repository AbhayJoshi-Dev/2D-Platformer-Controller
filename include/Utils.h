#pragma once

#include<SDL.h>
#include<iostream>
#include<cmath>

namespace utils
{
	static float currentTime = 0.f;
	static float lastTime = 0.f;
	static int fps;

	inline float HireTimeInSeconds()
	{
		float t = (float)SDL_GetTicks();
		t *= 0.001f;

		return t;
	}

	inline void FPS()
	{
		currentTime = (float)SDL_GetTicks();
		if ((currentTime - lastTime) >= 1000.f)
		{
			lastTime = currentTime;
			std::cout << fps << std::endl;
			fps = 0;
		}
		fps++;
	}

	inline float DegreesToRads(float degrees)
	{
		return degrees / 180 * 3.14f;
	}

	inline float RadsToDegrees(float rads)
	{
		return rads * 180 / 3.14f;
	}

	inline bool RangeIntersect(float min0, float max0, float min1, float max1)
	{
		return std::max(min0, max0) >= std::min(min1, max1) && 
			std::max(min1, max1) >= std::min(min0, max0);
	}

	inline bool IsCollision(Entity& e1, Entity& e2)
	{
		return RangeIntersect(e1.GetPosition().GetX(), e1.GetPosition().GetX() + e1.GetCurrentFrame().w, e2.GetPosition().GetX(), e2.GetPosition().GetX() + e2.GetCurrentFrame().w) &&
			RangeIntersect(e1.GetPosition().GetY(), e1.GetPosition().GetY() + e1.GetCurrentFrame().h, e2.GetPosition().GetY(), e2.GetPosition().GetY() + e2.GetCurrentFrame().h);
	}
}