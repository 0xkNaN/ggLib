/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:50:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 13:00:51
 */

#include "Actor.h"

#include "Game.h"
#include "TextureManager.h"

void Actor::load(const LoaderParams *params)
{
  Node::load(params);

  m_velocity = Vector2D(0, 0);
  m_acceleration = Vector2D(0, 0);

  m_textureId = params->getTextureId();
  m_currRow = 0;
  m_currFrame = 0;
  m_flip = SDL_FLIP_NONE;
}

void Actor::draw()
{
  TheTextureManager::Instance()->draw(
      TheGame::Instance()->getRenderer(),
      m_textureId,
      m_position.getX(),
      m_position.getY(),
      m_width,
      m_height,
      m_currRow,
      m_currFrame,
      m_angle,
      m_flip);
}

void Actor::update()
{
  m_velocity += m_acceleration;
  m_position += m_velocity;
}

void Actor::clean()
{
  Node::clean();
}
