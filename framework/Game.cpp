/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-11 13:34:08
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 21:11:25
 */

#include "Game.h"

#include "StateMenuMain.h"

#include "ObjectFactory.h"
#include "LoaderParams.h"
#include "InputHandler.h"

#include "Player.h"
#include "Enemy.h"
#include "UIButton.h"
#include "UIText.h"

Game *Game::s_pInstance = nullptr;

bool Game::init(std::string title, int winW, int winH)
{
  //? Init SDL
  int ini = SDL_Init(SDL_INIT_EVERYTHING);
  if (ini != 0)
    return false;

  //? Create SDL Window
  m_pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winW, winH, SDL_WINDOW_SHOWN);
  if (!m_pWindow)
    return false;

  //? Create SDL Renderer
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (!m_pRenderer)
    return false;

  //? Game Props
  m_name = title;
  m_windowW = winW;
  m_windowH = winH;

  //? Objecy Factory
  TheObjectFactory::Instance()->registerType("Player", new PlayerCreator());
  TheObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
  TheObjectFactory::Instance()->registerType("UIButton", new UIButtonCreator());
  TheObjectFactory::Instance()->registerType("UIText", new UITextCreator());

  //? State Machine
  m_stateMachine = new StateMachine();
  m_stateMachine->pushState(new StateMenuMain());

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
  //? Clear
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
  SDL_RenderClear(m_pRenderer);

  //? Update Current State
  m_stateMachine->render();

  //? Backbuffer technique
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
  TheInputHandler::Instance()->clean();

  m_stateMachine->clean();

  SDL_DestroyRenderer(m_pRenderer);
  SDL_DestroyWindow(m_pWindow);
  SDL_Quit();
}
