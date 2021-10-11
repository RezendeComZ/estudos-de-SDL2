#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
// :x(p_x), y(p_y), tex(p_tex) // é tipo fazer "x = p_x" dentro das chaves aqui em baixo
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

// float Entity::getX()
// {
// 	return x;
// }

// float Entity::getY()
// {
// 	return y;
// }

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}