/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:41:05
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:30:18
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "UIButton.h"

#include "StateMenu.h"
#include "StatePlay.h"

const char *StateMenu::s_menuId = "MENU";

void StateMenu::update()
{
  // std::cout << "StateMenu update :: " << m_gameObjects.size() << std::endl;

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateMenu::render()
{
  // std::cout << "StateMenu render :: " << m_gameObjects.size() << std::endl;

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

bool StateMenu::onEnter()
{
  std::cout << "StateMenu enter 1" << std::endl;

  //? Load Textures
  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->getRenderer(), "assets/play.png", "play_button"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->getRenderer(), "assets/exit.png", "exit_button"))
    return false;

  //? Game Objects
  Node *playBtn = new UIButton(s_menuToPlay);
  playBtn->load(new LoaderParams(320, 350, 400, 100, "play_button"));

  Node *exitBtn = new UIButton(s_exitFromMenu);
  exitBtn->load(new LoaderParams(320, 500, 400, 100, "exit_button"));

  m_gameObjects.push_back(playBtn);
  m_gameObjects.push_back(exitBtn);

  // #
  std::cout << "StateMenu enter 2" << std::endl;
  return true;
}

bool StateMenu::onExit()
{
  for (unsigned i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }

  m_gameObjects.clear();
  TheTextureManager::Instance()->clearTexture("play_button");
  TheTextureManager::Instance()->clearTexture("exit_button");

  // #
  std::cout << "StateMenu exit" << std::endl;
  return true;
}

void StateMenu::s_menuToPlay()
{
  TheGame::Instance()->getStateMachine()->changeState(new StatePlay());
}

void StateMenu::s_exitFromMenu()
{
  TheGame::Instance()->quit();
}