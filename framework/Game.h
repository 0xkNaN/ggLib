/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-12 15:12:38
 */

#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
public:
  Game(const char *title, int winW, int winH);
  ~Game();

  void init();
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return m_bRunning; }

private:
  std::string name;
  int windowW;
  int windowH;

  SDL_Window *m_pWindow = nullptr;
  SDL_Renderer *m_pRenderer = nullptr;

  bool m_bRunning = false;

  //? Texture
  SDL_Texture *m_pTexture;
  SDL_Rect m_srcRect;
  SDL_Rect m_dstRect;

  //? Sprite
  SDL_Texture *m_pSprite;
  SDL_Rect m_srcRectSprite;
  SDL_Rect m_dstRectSprite;

  //? TMP
  int m_currentFrame;
};
