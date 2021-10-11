#pragma once // Pra não copiar mais de uma vez os header desse arquivo // pra não importar novamente as coisas no include daqui, tipo no renderwindow.cpp ou main.cpp por exemplo // Aparentemente é sempre bom usar em todo header file
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

// Aqui as funções só são iniciadas, mas não tem o conteúdo delas, isso tem em "renderwindow.cpp":
class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // constructor // titulo, width e height // "p_" é de parâmetro
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void display();
private:
	SDL_Window* window; // * é um pointer // é a janela que carrega
	SDL_Renderer* renderer; // é o que renderiza as imagens
};