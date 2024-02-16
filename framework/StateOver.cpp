/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 23:29:06
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 00:13:03
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "UIButton.h"
#include "UIText.h"

#include "StateOver.h"
#include "StateMenu.h"
#include "StatePlay.h"

const char *StateOver::s_overId = "OVER";

void StateOver::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateOver::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

bool StateOver::onEnter()
{
  //? Load Textures
  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/gameover.png", "over_text"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/main.png", "main_button"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/restart.png", "restart_button"))
    return false;

  //? Game Over Text
  Node *overTxt = new UIText();
  overTxt->load(new LoaderParams(420, 200, 190, 30, "over_text", 2, 2));
  m_gameObjects.push_back(overTxt);

  //? Main Menu Button
  Node *mainBtn = new UIButton(s_onBtnOverHandler);
  mainBtn->load(new LoaderParams(420, 350, 200, 80, "main_button"));
  m_gameObjects.push_back(mainBtn);

  //? Restart Button
  Node *restartBtn = new UIButton(s_onBtnRestartGame);
  restartBtn->load(new LoaderParams(420, 450, 200, 80, "restart_button"));
  m_gameObjects.push_back(restartBtn);

  // #
  return true;
}

bool StateOver::onExit()
{
  for (unsigned i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->clean();
  }

  m_gameObjects.clear();
  TheTextureManager::Instance()->clearTexture("over_text");
  TheTextureManager::Instance()->clearTexture("main_button");
  TheTextureManager::Instance()->clearTexture("restart_button");

  TheInputHandler::Instance()->reset();

  // #
  return true;
}

void StateOver::s_onBtnOverHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StateMenu());
}

void StateOver::s_onBtnRestartGame()
{
  TheGame::Instance()->stateMachine()->changeState(new StatePlay());
}