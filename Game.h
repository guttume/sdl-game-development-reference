#ifndef SDLTEST_GAME_H
#define SDLTEST_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>

class Game {
public:
    bool init(const char*, int, int, int, int, bool);

    void render();

    void update();

    void handleEvents();

    void clean();

    bool running() const { return bRunning; }

private:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;

    int currFrame;
    bool bRunning;

};

#endif //SDLTEST_GAME_H
