/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 12:53:45
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 20:28:09
 */

#include <iostream>
#include <SDL2/SDL.h>

#include <SDL2/SDL.h>
#include "framework/Game.h"

#define WINW 640
#define WINH 480
#define FPS 60
#define FRAME_RATE 1000.0f / FPS

bool g_bRunning = false;

int main()
{

  bool init = TheGame::Instance()->init("ggLib Demo", WINW, WINH);

  if (!init)
  {
    std::cout << "SDL Error ::" << SDL_GetError() << std::endl;
    return -1;
  }

  //? Game Loop
  Uint32 frameStart, frameTime;
  while (TheGame::Instance()->running())
  {
    frameStart = SDL_GetTicks();

    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();

    //? Fixed Frame Rate
    frameTime = SDL_GetTicks() - frameStart;

    if (FRAME_RATE > frameTime)
    {
      SDL_Delay(int(FRAME_RATE - frameTime));
    }
  }

  //? Delay and Close
  TheGame::Instance()->clean();

  return 0;
}
