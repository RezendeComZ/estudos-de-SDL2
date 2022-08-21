#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

// Por padrão o conteúdo de uma class é private, e por padrão o conteúdo de um struct é public

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos()
	{
		return pos;
	}
	// float getX(); // retorna o valor que está na seção privada
	// float getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

private:
	Vector2f pos; // pos de posição
	// float x, y; // X é horizontal, Y é vertical // é onde a entidade estará na tela, se fosse 3D também teria Z
	SDL_Rect currentFrame; // vai ajudar mais pra frente com animação mas já serve pra tiles
	SDL_Texture* tex;
};