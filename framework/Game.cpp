/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-12 21:30:59
 */

#include "Game.h"

#include "TextureManager.h"

Game *Game::s_pInstance = nullptr;

Game::~Game()
{
}

void Game::init(const char *title, int winW, int winH)
{
  //? Init SDL
  int ini = SDL_Init(SDL_INIT_EVERYTHING);
  if (ini != 0)
    return;

  //? Create SDL Window
  m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winW, winH, SDL_WINDOW_SHOWN);
  if (!m_pWindow)
    return;

  //? Create SDL Renderer
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (!m_pRenderer)
    return;

  //? Load the Textures
  TheTextureManager::Instance()->load(m_pRenderer, "assets/rider.bmp", "rider");
  TheTextureManager::Instance()->load(m_pRenderer, "assets/animate-alpha.png", "sprite");

  // #
  m_bRunning = true;
}

void Game::handleEvents()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
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
  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
  //? Clear with black color
  SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
  SDL_RenderClear(m_pRenderer);

  //? Draw a Rect
  SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
  SDL_Rect tRect;
  tRect.x = 0;
  tRect.y = 0;
  tRect.w = 125;
  tRect.h = 89;
  SDL_RenderDrawRect(m_pRenderer, &tRect);

  //? Draw the texture
  TheTextureManager::Instance()->draw(m_pRenderer, "rider", 0, 0, 125, 89, 0, 0, SDL_FLIP_NONE);

  //? Draw the sprite
  TheTextureManager::Instance()->draw(m_pRenderer, "sprite", 0, 100, 128, 82, 0, m_currentFrame, SDL_FLIP_NONE);

  // #
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}
