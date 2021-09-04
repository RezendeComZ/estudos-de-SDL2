#pragma once // Pra não copiar mais de uma vez vezes os includes // tipo pra não importar novamente no renderwindow.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	void cleanUp();
private:
	SDL_Window* window; // * é um pointer // é a janela mesmo que carrega
	SDL_Renderer* renderer; // é o que renderiza as imagens
};