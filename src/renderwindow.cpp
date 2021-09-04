#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL) // pra testar (?)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN); // WINDOWPOS_UNDEFINED é pq não está definido onde a janela vai aparecer

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // renderizar em uma "window" // -1 é onde quero renderizar, -1 é indicando o driver que vai satisfazer tudo que preciso // Se tiver placa de vídeo com aceleração o último parâmetro indica para usar
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}