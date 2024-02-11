/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-11 15:02:54
 */

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();

  void init(const char *title, int winW, int winH);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return m_bRunning; }

private:
  SDL_Window *m_pWindow = nullptr;
  SDL_Renderer *m_pRenderer = nullptr;

  bool m_bRunning = false;
};
