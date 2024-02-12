/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 12:53:45
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-11 15:51:08
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "framework/Game.h"

#define WINW 1280
#define WINH 960

Game *game = nullptr;

bool g_bRunning = false;

int main()
{
  Game *game = new Game("Demo Game using ggLib", WINW, WINH);

  game->init();
  if (!game->running())
  {
    std::cout << "SDL Error ::" << SDL_GetError() << std::endl;
    return -1;
  }

  //? Game Loop
  while (game->running())
  {
    game->handleEvents();
    game->update();
    game->render();
  }

  //? Delay and Close
  game->clean();

  return 0;
}
