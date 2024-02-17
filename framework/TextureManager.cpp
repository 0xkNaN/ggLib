/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-12 13:41:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:04:17
 */

#include "TextureManager.h"

TextureManager *TextureManager::s_pInstance = nullptr;

TextureManager::~TextureManager()
{
}

bool TextureManager::load(SDL_Renderer *renderer, std::string file, std::string id)
{
  SDL_Surface *tmpSurf = IMG_Load(file.c_str());
  if (tmpSurf == 0)
    return false;

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurf);
  SDL_FreeSurface(tmpSurf);

  if (texture == 0)
    return false;

  //? Save texture
  m_texturesMap[id] = texture;
  return true;
}

void TextureManager::draw(
    SDL_Renderer *renderer, std::string id,
    int x, int y, int width, int height, int currRow, int currFrame,
    double angle, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect dstRect;

  srcRect.x = width * currFrame;
  srcRect.y = height * currRow;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = srcRect.w = width;
  dstRect.h = srcRect.h = height;

  SDL_RenderCopyEx(renderer, m_texturesMap[id], &srcRect, &dstRect, angle, 0, flip);
}

void TextureManager::clearTexture(std::string id)
{
  m_texturesMap.erase(id);
}