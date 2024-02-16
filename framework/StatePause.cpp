/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 21:37:05
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 00:12:53
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "UIButton.h"

#include "StatePause.h"
#include "StateMenu.h"

const char *StatePause::s_pauseId = "PAUSE";

void StatePause::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }
}

void StatePause::render()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

bool StatePause::onEnter()
{
  //? Load Textures
  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/main.png", "main_button"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/resume.png", "resume_button"))
    return false;

  //? Game Objects
  Node *playBtn = new UIButton(s_onBtnPauseHandler);
  playBtn->load(new LoaderParams(420, 350, 200, 80, "main_button"));

  Node *resumeBtn = new UIButton(s_onBtnResumeGame);
  resumeBtn->load(new LoaderParams(420, 450, 200, 80, "resume_button"));

  m_gameObjects.push_back(playBtn);
  m_gameObjects.push_back(resumeBtn);

  // #
  return true;
}

bool StatePause::onExit()
{
  for (unsigned i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->clean();
  }

  m_gameObjects.clear();
  TheTextureManager::Instance()->clearTexture("main_button");
  TheTextureManager::Instance()->clearTexture("resume_button");

  TheInputHandler::Instance()->reset();

  // #
  return true;
}

void StatePause::s_onBtnPauseHandler()
{
  TheGame::Instance()->stateMachine()->changeState(new StateMenu());
}

void StatePause::s_onBtnResumeGame()
{
  TheGame::Instance()->stateMachine()->popState();
}