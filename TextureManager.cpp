#include "TextureManager.h"
#include "SDL_image.h"

bool TextureManager::load(const std::string &filename, const std::string &id, SDL_Renderer *pRenderer) {
    SDL_Surface *tempSurface = IMG_Load(filename.c_str());

    if (!tempSurface) {
        return false;
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (pTexture) {
        textureMap[id] = pTexture;
        return true;
    }

    return false;
}

void TextureManager::draw(const std::string &id, int x, int y, int width, int height, SDL_Renderer *pRenderer,
                          SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect, &destRect, 0, nullptr, flip);

}

void TextureManager::drawFrame(const std::string& id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer *pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect, &destRect, 0, nullptr, flip);

}

TextureManager* TextureManager::pInstance = nullptr;
