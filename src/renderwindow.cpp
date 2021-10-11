#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp" // o #pragma once tá impedindo de carregar novamente os mesmos includes
#include "Entity.hpp"

// Essas funções foram declaradas em "RenderWindows.cpp":
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL) // pra testar se inicializou a janela
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN); // WINDOWPOS_UNDEFINED é pq não está definido onde a janela vai aparecer

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // renderizar em "window" // -1 é onde quero renderizar, -1 é indicando o driver que vai satisfazer tudo que preciso // Se tiver uma placa de vídeo com aceleração o último parâmetro indica para usar ela
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x * 4;
	dst.y = p_entity.getPos().y * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst); // Já não mais mais NULLs: O primeiro NULL era o source da textura, o outro era o destino
}; 


void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}