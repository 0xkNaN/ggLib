/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 23:52:34
 */

#include <iostream>

#include "Game.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "InputHandler.h"

#include "Node.h"
#include "Player.h"
#include "Enemy.h"

#include "StatePlay.h"
#include "StatePause.h"
#include "StateOver.h"

const char *StatePlay::s_playId = "PLAY";

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
    TheGame::Instance()->stateMachine()->pushState(new StatePause());
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
          TheGame::Instance()->stateMachine()->pushState(new StateOver());
        }
      }
    }
  }
}

bool StatePlay::onEnter()
{
  //? Load Textures
  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/helicopter.png", "player"))
    return false;

  if (!TheTextureManager::Instance()->load(
          TheGame::Instance()->renderer(), "assets/helicopter2.png", "enemy"))
    return false;

  //? Player
  Player *player = new Player();
  player->load(new LoaderParams(30, 300, 128, 55, "player", 4));
  m_gameObjects.push_back(player);

  //? Player
  Enemy *enemy = new Enemy();
  enemy->load(new LoaderParams(850, 300, 128, 55, "enemy", 4));
  m_gameObjects.push_back(enemy);

  //? Area Test
  // Node *area = new Node();
  // area->load(new LoaderParams(460, 300, 100, 55, NULL));
  // m_gameObjects.push_back(area);

  // #
  return true;
}

bool StatePlay::onExit()
{
  for (unsigned i = 0; i < m_gameObjects.size(); i++)
  {
    m_gameObjects[i]->clean();
  }

  m_gameObjects.clear();
  TheTextureManager::Instance()->clearTexture("player");
  TheTextureManager::Instance()->clearTexture("enemy");

  TheInputHandler::Instance()->reset();

  // #
  return true;
}
