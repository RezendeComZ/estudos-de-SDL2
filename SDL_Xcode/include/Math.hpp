#pragma once

#include <iostream>

struct Vector2f // f pq vai ser float // class por padrão é private, struct por padrão é public, essa é a diferença
{
	Vector2f()
	:x(0.0f), y(0.0f) // inicializando
	{}

	Vector2f(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};