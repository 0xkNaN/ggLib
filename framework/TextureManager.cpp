/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-12 13:41:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-12 15:34:50
 */

#include "TextureManager.h"

TextureManager *TextureManager::s_pInstance = 0;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::load(SDL_Renderer *renderer, const char *file, const char *id)
{
  SDL_Surface *tmpSurf = IMG_Load(file);
  if (tmpSurf == 0)
    return false;

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurf);
  SDL_FreeSurface(tmpSurf);

  if (texture == 0)
    return false;

  //? Add texture in the list with the id
  m_texturesMap[id] = texture;
  return true;
}

void TextureManager::draw(SDL_Renderer *renderer, const char *id, int x, int y, int width, int height, int currRow, int currFrame, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect dstRect;

  srcRect.x = width * currFrame;
  srcRect.y = height * currRow;
  dstRect.x = x;
  dstRect.y = y;
  dstRect.w = srcRect.w = width;
  dstRect.h = srcRect.h = height;

  SDL_RenderCopyEx(renderer, m_texturesMap[id], &srcRect, &dstRect, 0, 0, flip);
}
