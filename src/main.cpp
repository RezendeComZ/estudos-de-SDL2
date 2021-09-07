#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp" // Dá pra usar aspas duplas para o include, vale a pena usar em coisas que eu mesmo criei (no caso foi o codergopher. Para não misturar com outros headers.

int main(int argc, char* args[])
{
	// Validações:
	if (SDL_Init(SDL_INIT_VIDEO) > 0) // inicia o SDL, e se retornar 0 tá tudo certo
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG))) // Inicia o SDL_Image // enum
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	// Criando uma janela/objeto chamado "window":
	RenderWindow window("Joguin v1.0", 500, 600); // inicia a janela e o tamanho da janela

	// Criando um objeto de textura e indicando que é pra carregar na janela "window"
	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

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
		window.render(grassTexture);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0; // cpp não precisa retornar 0, é uma coisa que é SDL pede
}