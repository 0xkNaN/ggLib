/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:08:59
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "StateParser.h"

#include "StatePlay.h"
#include "StateMenuPause.h"
#include "StateMenuOver.h"

std::string StatePlay::s_playId = "state_play_demo";

void StatePlay::update()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }

  checkCollision();
}

void StatePlay::render()
{
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_ESCAPE))
  {
    TheGame::Instance()->stateMachine()->pushState(new StateMenuPause());
  }

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->draw();
  }
}

void StatePlay::checkCollision()
{
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    for (int j = 0; j < m_gameObjects.size(); j++)
    {
      if (i != j)
      {
        SDL_Rect iCollider = m_gameObjects[i]->collider();
        SDL_Rect jCollider = m_gameObjects[j]->collider();

        if (SDL_HasIntersection(&iCollider, &jCollider))
        {
          TheGame::Instance()->stateMachine()->pushState(new StateMenuOver());
        }
      }
    }
  }
}

bool StatePlay::onEnter()
{
  //? Parse State
  StateParser stateParser;
  stateParser.parseState("states.xml", s_playId, &m_gameObjects, &m_textureIdList);

  // //? Load Textures
  // if (!TheTextureManager::Instance()->load(
  //         TheGame::Instance()->renderer(), "assets/helicopter.png", "player"))
  //   return false;

  // if (!TheTextureManager::Instance()->load(
  //         TheGame::Instance()->renderer(), "assets/helicopter2.png", "enemy"))
  //   return false;

  // //? Player
  // Player *player = new Player();
  // player->load(new LoaderParams(30, 300, 128, 55, "player", 4));
  // m_gameObjects.push_back(player);

  // //? Player
  // Enemy *enemy = new Enemy();
  // enemy->load(new LoaderParams(850, 300, 128, 55, "enemy", 4));
  // m_gameObjects.push_back(enemy);

  // #
  return true;
}

bool StatePlay::onExit()
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
