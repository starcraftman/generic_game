#include <SDL/SDL.h>

#include "game.hpp"

namespace vConsts {
    const int screenWidth = 640;
    const int screenHeight = 480;
    const int kBitsPerPixel = 32;
    const int kFPS = 60;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(SDL_DISABLE);
    this->screen_ = SDL_SetVideoMode(
            vConsts::screenWidth,
            vConsts::screenHeight,
            vConsts::kBitsPerPixel,
            SDL_FULLSCREEN
    );

    eventLoop();
}

Game::~Game() {
    SDL_Quit();
}

void Game::eventLoop() {
    SDL_Event event;

    bool running = true;
    while (running) {
        const int start_ms = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    // Break game loop on Escape.
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        running = false;
                    }
                default:
                    break;
            }
        }

        update();
        draw();

        const int elapsed_ms = SDL_GetTicks() - start_ms;
        SDL_Delay(1000 / vConsts::kFPS - elapsed_ms);
    }
}

void Game::update() {

}

void Game::draw() {

}
