#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp" // Dá pra usar aspas duplas para o include, vale a pena usar em coisas que eu mesmo criei (no caso foi o codergopher). Para não misturar com outros headers.
#include "Entity.hpp"

int main(int argc, char* args[])
{
	// Validações:
	if (SDL_Init(SDL_INIT_VIDEO) > 0) // inicia o SDL, e se retornar 0 tá tudo certo, se retorna 1 é pq quebrou, acho que poderia ser apenas '!SDL_Init(SDL_INIT_VIDEO)', ou não?
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG))) // Inicia o SDL_Image // É um ENUM
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	// Criando uma janela/objeto chamado "window":
	RenderWindow window("Joguin v1.0", 1280, 720); // inicia a janela e o tamanho da janela

	// Criando um objeto de textura e indicando que é pra carregar na janela "window":
	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	// Entity platform0(100, 50, grassTexture); // Entidade criada
	// Entity platform1(56, 90, grassTexture); // outra entidade criada

	// Entity entities[4] = {Entity(0, 0, grassTexture),
	// 					  Entity(30, 0, grassTexture),
	// 					  Entity(30, 30, grassTexture),
	// 					  Entity(30, 60, grassTexture)};

	std::vector<Entity> entities2 = {Entity(Vector2f(0, 0), grassTexture),
                         			 Entity(Vector2f(30, 0), grassTexture),
                          			 Entity(Vector2f(30, 30), grassTexture),
                          			 Entity(Vector2f(30, 60), grassTexture)};

	{	// Essas chaves vão limitar o uso de memória, liberando a memória
		Entity coisinha(Vector2f(100, 50), grassTexture); // adicionando outra entidade na list ade cima

		entities2.push_back(coisinha);
	}

	bool gameRunning = true;

	SDL_Event event; // criando um objeto evento chamado "event"

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		// window.render(platform0); // render da primeira entidade
		// window.render(platform1); // render da segunda

		for (Entity& e : entities2) // poderia usar "auto" // "e" pode ser qualquer coisa
		{
			window.render(e);
		}

		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0; // cpp não precisa retornar 0, é uma coisa que é SDL pede (de acordo como codegopher)
}