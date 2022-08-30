#include <stdio.h>
#include <SDL2/SDL.h>
#include "./constants.h" // aspas pq está na mesma pasta

int game_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0;

struct ball {
  float x;
  float y;
  float width;
  float height;
} ball; // já declarando

int initialize_window(void) { // void é opcinal nos parametros, mas é bom para deixar claro que não recebe nada
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Erro inicializando o SDL.\n");
    return FALSE;
  }
  window = SDL_CreateWindow(
    "Joguin", // Titulo da janela
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN // no tutorial original é SDL_WINDOW_BORDERLESS
  );
  if (!window) {
    fprintf(stderr, "Erro ao criar janela do SDL.\n");
    return FALSE;
  }

  renderer = SDL_CreateRenderer(
    window, // a que configuramos em cima
    -1, // driver de video, defaut
    0 // flags específicas. 0 para nenhuma
  );
  if (!renderer) {
        fprintf(stderr, "Erro ao criar renderizador do SDL.\n");
        return FALSE;
  }
  return TRUE;
}

void process_input() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT: // Quando o usuário fecha a janela
    game_is_running = FALSE;
    break;
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      game_is_running = FALSE;
      break;
    }
  
  // default:
  //   break;
  }

}

void setup() {
  ball.x = 20;
  ball.y = 20;
  ball.width = 15;
  ball.height = 15;
}

void update() {
  // Espera o tempo até chegar no momento do frame:
  // while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME)); // funciona mas gasta muita CPU
  int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

  if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
    SDL_Delay(time_to_wait);
  }

  // Get a delta time factor converted to seconds to be used to update my objects:
  float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;

  last_frame_time = SDL_GetTicks();

  ball.x += 70 * delta_time; // pixels por segundo
  ball.y += 50 * delta_time; // pixels por segundo
}

void render() {
  SDL_SetRenderDrawColor(renderer, 150, 0, 0, 255); // neste caso está servindo como cor de fundo
  SDL_RenderClear(renderer);

  // Desenha um retangulo:
  SDL_Rect ball_rect = {
    (int)ball.x,
    (int)ball.y,
    (int)ball.width,
    (int)ball.height
  };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderFillRect(renderer, &ball_rect);

  SDL_RenderPresent(renderer);
}

void destroy_window() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main() {
  // printf("hello world\n");
  game_is_running = initialize_window();

  setup();

  while (game_is_running) {
    process_input();
    update();
    render();
  }

  destroy_window();

  return 0;
}