/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:53:50
 */

#include "Game.h"

#include "StateMenu.h"
#include "StatePlay.h"

#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"

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

  //? State Machine
  m_stateMachine = new StateMachine();
  m_stateMachine->pushState(new StateMenu());

  //? Load the Textures
  TheTextureManager::Instance()->load(m_pRenderer, "assets/helicopter.png", "player");
  TheTextureManager::Instance()->load(m_pRenderer, "assets/helicopter2.png", "enemy");

  //? Init InputHandler
  TheInputHandler::Instance()->initJoysticks();

  // #
  m_bRunning = true;
  return true;
}

void Game::handleEvents()
{
  TheInputHandler::Instance()->update();
}

void Game::update()
{
  m_stateMachine->update();
}

void Game::render()
{
  //? Clear with black color
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(m_pRenderer);

  //? Update Current State
  m_stateMachine->render();

  //? Backbuffer technique
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  m_stateMachine->clean();

  TheInputHandler::Instance()->clean();

  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}
