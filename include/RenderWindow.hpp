#pragma once // Pra não copiar mais de uma vez os header desse arquivo // pra não importar novamente no renderwindow.cpp por exemplo
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // constructor
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(SDL_Texture* p_text);
	void display();
private:
	SDL_Window* window; // * é um pointer // é a janela que carrega
	SDL_Renderer* renderer; // é o que renderiza as imagens
};