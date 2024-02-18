/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-12 13:41:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 15:58:21
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

  bool load(SDL_Renderer *renderer, std::string file, std::string id);

  void render(
      SDL_Renderer *renderer, std::string id,
      int x, int y, int width, int height, int currRow = 0, int currFrame = 0,
      double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void renderTile(
      SDL_Renderer *renderer, std::string id,
      int margin, int spacing,
      int x, int y, int width, int height,
      int currRow = 0, int currFrame = 0);

  std::map<std::string, SDL_Texture *> textureMap() const { return m_texturesMap; }

  void clearTexture(std::string id);

private:
  TextureManager() {}

  static TextureManager *s_pInstance;

  std::map<std::string, SDL_Texture *> m_texturesMap;
};

typedef TextureManager TheTextureManager;