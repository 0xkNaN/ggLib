/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:41:05
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 00:12:16
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "UIButton.h"

#include "StateMenu.h"
#include "StatePlay.h"

const char *StateMenu::s_menuId = "MENU";

void StateMenu::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateMenu::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

bool StateMenu::onEnter()
{
  //? Load Textures
  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/play.png", "play_button"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/exit.png", "exit_button"))
    return false;

  //? Play Button
  Node *playBtn = new UIButton(s_onBtnPlayHandler);
  playBtn->load(new LoaderParams(320, 350, 400, 100, "play_button"));
  m_gameObjects.push_back(playBtn);

  //? Exit Button
  Node *exitBtn = new UIButton(s_onBtnExitGame);
  exitBtn->load(new LoaderParams(320, 500, 400, 100, "exit_button"));
  m_gameObjects.push_back(exitBtn);

  // #
  return true;
}

bool StateMenu::onExit()
{
  for (unsigned i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->clean();
  }

  m_gameObjects.clear();
  TheTextureManager::Instance()->clearTexture("play_button");
  TheTextureManager::Instance()->clearTexture("exit_button");

  TheInputHandler::Instance()->reset();

  // #
  return true;
}

void StateMenu::s_onBtnPlayHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StatePlay());
}

void StateMenu::s_onBtnExitGame()
{
  TheGame::Instance()->quit();
}