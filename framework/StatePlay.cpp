/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 21:14:18
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "LevelParser.h"
#include "StateParser.h"

#include "StatePlay.h"
#include "StateMenuPause.h"
#include "StateMenuOver.h"

std::string StatePlay::s_playId = "state_play_demo";

void StatePlay::update()
{

  level->update();

  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->update();
  }

  // checkCollision();
}

void StatePlay::render()
{
  //? Clear with a blue color -- sky
  SDL_SetRenderDrawColor(TheGame::Instance()->renderer(), 45, 162, 242, 255);
  SDL_RenderClear(TheGame::Instance()->renderer());

  //? Render Level Tiles
  level->render();

  //? Render Game Objects
  for (int i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->render();
  }

  //? MenuPause
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_ESCAPE))
  {
    TheGame::Instance()->stateMachine()->pushState(new StateMenuPause());
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
  //? Parse Level
  LevelParser levelParser;
  level = levelParser.parseLevel("assets/map.xml");

  //? Parse State
  StateParser stateParser;
  stateParser.parseState("states.xml", s_playId, &m_gameObjects, &m_textureIdList);

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
