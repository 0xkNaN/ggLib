/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-12 13:41:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 22:28:04
 */
#pragma once

#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager
{
public:
  ~TextureManager();

  static TextureManager *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new TextureManager();
    return s_pInstance;
  }

  bool load(SDL_Renderer *renderer, const char *file, const char *id);
  void draw(
      SDL_Renderer *renderer, const char *id,
      int x, int y, int width, int height, int currRow = 0, int currFrame = 0,
      double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);

  std::map<const char *, SDL_Texture *> textureMap() const { return m_texturesMap; }

  void clearTexture(const char *id);

private:
  TextureManager() {}

  static TextureManager *s_pInstance;

  std::map<const char *, SDL_Texture *> m_texturesMap;
};

typedef TextureManager TheTextureManager;