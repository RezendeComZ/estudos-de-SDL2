#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp" // Dá pra usar aspas duplas para o include, vale a pena usar em coisas que eu mesmo crio, para não misturar

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("Joguin v1.0", 500, 600); // iniciar a janela e o tamanho da janela

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	bool gameRunning = true;

	SDL_Event event;

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