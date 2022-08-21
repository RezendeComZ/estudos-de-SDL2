// Fonte do tutorial: https://www.youtube.com/watch?v=lHAUc6F_B3Y
// Playlist: https://www.youtube.com/watch?v=44tO977slsU&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=3
//  main.cpp
//  SDL_Xcode
//
//  Created by gabrezende on 07/09/21.
//  Copyright © 2021 gabrezende. All rights reserved.
//
#include "SDL2/SDL.h"
#include <iostream>

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Window *window = SDL_CreateWindow("Titulo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_SetRenderDrawColor(renderer, 200, 20, 20, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(5000);
}
