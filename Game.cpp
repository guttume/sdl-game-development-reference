
#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if (pWindow != nullptr) {
            std::cout << "Window creation success\n";
            pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

            if (pRenderer != nullptr) {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
            } else {
                std::cout << "renderer init fail\n";
                return false;
            }
        } else {
            std::cout << "window init fail\n";
            return false;
        }
    } else {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    std::cout << "init success\n";
    bRunning = true; // everything initiated successfully, start the main loop

    if(!TheTextureManager::Instance()->load("../assets/animate-alpha.png", "animate", pRenderer)) {
        return false;
    }

    return true;
}

void Game::render() {
    SDL_RenderClear(pRenderer);

    TheTextureManager::Instance()->draw("animate", 0, 0 , 128, 82, pRenderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, currFrame, pRenderer);

    SDL_RenderPresent(pRenderer);
}

void Game::clean() {
    std::cout << "Cleaning game\n";
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::update() {
    currFrame = int(((SDL_GetTicks() / 100) % 6));
}
