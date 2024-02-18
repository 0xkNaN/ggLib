/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 23:29:06
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:08:01
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StateParser.h"

#include "StateMenuOver.h"
#include "StateMenuMain.h"
#include "StatePlay.h"

#include "UIButton.h"
#include "UIText.h"

std::string StateMenuOver::s_overId = "state_menu_over";

void StateMenuOver::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateMenuOver::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->render();
  }
}

bool StateMenuOver::onEnter()
{
  //? Parse State
  StateParser stateParser;
  stateParser.parseState("states.xml", s_overId, &m_gameObjects, &m_textureIdList);
  m_callbacks.push_back(0);
  m_callbacks.push_back(s_onBtnOverHandler);
  m_callbacks.push_back(s_onBtnRestartGame);

  setCallbacks(m_callbacks);

  // #
  return true;
}

bool StateMenuOver::onExit()
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

void StateMenuOver::setCallbacks(const std::vector<Callback> &callbacks)
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

void StateMenuOver::s_onBtnOverHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StateMenuMain());
}

void StateMenuOver::s_onBtnRestartGame()
{
  TheGame::Instance()->stateMachine()->changeState(new StatePlay());
}