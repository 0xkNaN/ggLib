/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-11 15:07:30
 */

#include "Game.h"
#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int winW, int winH)
{
  //? Init SDL
  int ini = SDL_Init(SDL_INIT_EVERYTHING);
  if (ini != 0)
    return;

  //? Create SDL Window
  m_pWindow = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      winW,
      winH,
      SDL_WINDOW_SHOWN);
  if (!m_pWindow)
    return;

  //? Create SDL Renderer
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (!m_pRenderer)
    return;

  // #
  m_bRunning = true;
}

void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      m_bRunning = false;
      break;
    default:
      break;
    }
  }
}

void Game::update()
{
  //!
}

void Game::render()
{
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}
