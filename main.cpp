/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 12:53:45
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-12 21:31:48
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "framework/Game.h"

#define WINW 1024
#define WINH 768

bool g_bRunning = false;

int main()
{

  TheGame::Instance()->init("ggLib Demo", WINW, WINH);
  if (!TheGame::Instance()->running())
  {
    std::cout << "SDL Error ::" << SDL_GetError() << std::endl;
    return -1;
  }

  //? Game Loop
  while (TheGame::Instance()->running())
  {
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
  }

  //? Delay and Close
  TheGame::Instance()->clean();

  return 0;
}
