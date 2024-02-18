/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 12:05:36
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:07:52
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StateParser.h"

#include "StateMenuMain.h"
#include "StatePlay.h"

#include "UIButton.h"

std::string StateMenuMain::s_menuId = "state_menu_main";

void StateMenuMain::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateMenuMain::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->render();
  }
}

bool StateMenuMain::onEnter()
{
  //? Parse State
  StateParser stateParser;
  stateParser.parseState("states.xml", s_menuId, &m_gameObjects, &m_textureIdList);
  m_callbacks.push_back(0);
  m_callbacks.push_back(s_onBtnPlayHandler);
  m_callbacks.push_back(s_onBtnExitGame);
  setCallbacks(m_callbacks);

  // #
  return true;
}

bool StateMenuMain::onExit()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->clean();
  }

  m_gameObjects.clear();

  for (int i = 0; i < m_textureIdList.size(); i++)
  {
    TheTextureManager::Instance()->clearTexture(m_textureIdList[i].c_str());
  }

  TheInputHandler::Instance()->reset();

  // #
  return true;
}

void StateMenuMain::setCallbacks(const std::vector<Callback> &callbacks)
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    //? If Object of type UIButton then assign a callback
    if (dynamic_cast<UIButton *>(m_gameObjects[i]))
    {
      UIButton *btn = dynamic_cast<UIButton *>(m_gameObjects[i]);
      btn->setCallback(callbacks[btn->callbackId()]);
    }
  }
}

void StateMenuMain::s_onBtnPlayHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StatePlay());
}

void StateMenuMain::s_onBtnExitGame()
{
  TheGame::Instance()->quit();
}