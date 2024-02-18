/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 15:43:41
 */
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "StateMachine.h"
#include "Node.h"

class Game
{
public:
  ~Game() {}

  static Game *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new Game();
    return s_pInstance;
  }

  bool init(std::string title, int winW, int winH);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return m_bRunning; }
  void quit() { m_bRunning = false; }

  std::string gameName() const { return m_name; }
  int gameWidth() const { return m_windowW; }
  int gameHeight() const { return m_windowH; }

  SDL_Renderer *renderer() const { return m_pRenderer; }
  StateMachine *stateMachine() const { return m_stateMachine; }

private:
  Game() {}

  static Game *s_pInstance;

  std::string m_name;
  int m_windowW;
  int m_windowH;

  SDL_Window *m_pWindow = nullptr;
  SDL_Renderer *m_pRenderer = nullptr;

  bool m_bRunning = false;

  StateMachine *m_stateMachine;
};

typedef Game TheGame;
