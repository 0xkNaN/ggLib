/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:50:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:43:01
 */

#include "Node.h"

#include "Game.h"
#include "TextureManager.h"

void Node::load(const LoaderParams *params)
{
  m_position = Vector2D(params->getX(), params->getY());
  m_velocity = Vector2D(0, 0);
  m_acceleration = Vector2D(0, 0);

  m_width = params->getWidth();
  m_height = params->getHeight();

  m_textureId = params->getTextureId();
  m_currRow = 0;
  m_currFrame = 0;
  m_flip = SDL_FLIP_NONE;
}

void Node::draw()
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
      m_flip);
}

void Node::update()
{
  m_velocity += m_acceleration;
  m_position += m_velocity;
}

void Node::clean()
{
}
