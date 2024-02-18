/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:50:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:05:27
 */

#include "Actor.h"

#include "Game.h"
#include "TextureManager.h"

void Actor::load(const LoaderParams *params)
{
  Node::load(params);

  m_textureId = params->textureId();
  m_numFrames = params->numFrames();

  m_velocity = Vector2D(0, 0);
  m_acceleration = Vector2D(0, 0);

  m_currRow = 0;
  m_currFrame = 0;
  m_angle = 0;
  m_flip = SDL_FLIP_NONE;
}

void Actor::update()
{
  m_velocity += m_acceleration;
  m_position += m_velocity;

  Node::update();
}

void Actor::render()
{
  TheTextureManager::Instance()->render(
      TheGame::Instance()->renderer(),
      m_textureId,
      m_position.x(),
      m_position.y(),
      m_width,
      m_height,
      m_currRow,
      m_currFrame,
      m_angle,
      m_flip);

  Node::render();
}

void Actor::clean()
{
  Node::clean();
}
