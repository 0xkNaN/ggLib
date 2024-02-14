/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 13:09:05
 */

#include "Game.h"

#include "TextureManager.h"
#include "LoaderParams.h"

#include "Player.h"
#include "Enemy.h"

Game *Game::s_pInstance = nullptr;

Game::~Game()
{
}

bool Game::init(const char *title, int winW, int winH)
{
  //? Init SDL
  int ini = SDL_Init(SDL_INIT_EVERYTHING);
  if (ini != 0)
    return false;

  //? Create SDL Window
  m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winW, winH, SDL_WINDOW_SHOWN);
  if (!m_pWindow)
    return false;

  //? Create SDL Renderer
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (!m_pRenderer)
    return false;

  //? Load the Textures
  TheTextureManager::Instance()->load(m_pRenderer, "assets/animate-alpha.png", "sprite");
  TheTextureManager::Instance()->load(m_pRenderer, "assets/rider.bmp", "rider");

  //? Game Object
  m_gameObjects.push_back(new Player(new LoaderParams(0, 300, 125, 89, "sprite")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(900, 300, 128, 82, "rider")));

  // #
  m_bRunning = true;
  return true;
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
  for (std::vector<Object *>::size_type i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void Game::render()
{
  //? Clear with black color
  SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
  SDL_RenderClear(m_pRenderer);

  //? Draw GameObjects
  for (std::vector<Object *>::size_type i = 0; i != m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  //? Backbuffer technique
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}
