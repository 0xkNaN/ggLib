/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 21:37:05
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:08:58
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StateParser.h"

#include "StateMenuPause.h"
#include "StateMenuMain.h"

#include "UIButton.h"

std::string StateMenuPause::s_pauseId = "state_menu_pause";

void StateMenuPause::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StateMenuPause::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->render();
  }
}

bool StateMenuPause::onEnter()
{
  //? Parse State
  StateParser stateParser;
  stateParser.parseState("states.xml", s_pauseId, &m_gameObjects, &m_textureIdList);
  m_callbacks.push_back(0);
  m_callbacks.push_back(s_onBtnPauseHandler);
  m_callbacks.push_back(s_onBtnResumeGame);

  setCallbacks(m_callbacks);

  // //? Load Textures
  // if (!TheTextureManager::Instance()->load(
  //         TheGame::Instance()->renderer(), "assets/main.png", "main_button"))
  //   return false;

  // if (!TheTextureManager::Instance()->load(
  //         TheGame::Instance()->renderer(), "assets/resume.png", "resume_button"))
  //   return false;

  // //? Game Objects
  // Node *playBtn = new UIButton(s_onBtnPauseHandler);
  // playBtn->load(new LoaderParams(420, 350, 200, 80, "main_button"));

  // Node *resumeBtn = new UIButton(s_onBtnResumeGame);
  // resumeBtn->load(new LoaderParams(420, 450, 200, 80, "resume_button"));

  // m_gameObjects.push_back(playBtn);
  // m_gameObjects.push_back(resumeBtn);

  // #
  return true;
}

bool StateMenuPause::onExit()
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

void StateMenuPause::setCallbacks(const std::vector<Callback> &callbacks)
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

void StateMenuPause::s_onBtnPauseHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StateMenuMain());
}

void StateMenuPause::s_onBtnResumeGame()
{
  TheGame::Instance()->stateMachine()->popState();
}