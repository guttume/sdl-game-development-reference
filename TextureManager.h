
#ifndef SDLTEST_TEXTUREMANAGER_H
#define SDLTEST_TEXTUREMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include "SDL.h"


class TextureManager {
public:
    static TextureManager *Instance() {
        if (pInstance == nullptr) {
            pInstance = new TextureManager();
        }

        return pInstance;
    }

    bool load(const std::string &filename, const std::string &id, SDL_Renderer *pRenderer);

    void draw(const std::string &id, int x, int y, int width, int height, SDL_Renderer *pRenderer,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(const std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame,
                   SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    std::map<std::string, SDL_Texture *> textureMap;
private:
    TextureManager() = default;

    static TextureManager *pInstance;
};

typedef TextureManager TheTextureManager;


#endif //SDLTEST_TEXTUREMANAGER_H
