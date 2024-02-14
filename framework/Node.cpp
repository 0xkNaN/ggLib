/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:50:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 13:04:20
 */

#include "Node.h"

#include "Game.h"
#include "TextureManager.h"

Node::Node(const LoaderParams *params) : Object(params)
{
  std::cout << "Node init:: " << params->getTextureId() << params->getX() << params->getY() << params->getWidth() << params->getHeight() << std::endl;

  m_x = params->getX();
  m_y = params->getY();
  m_width = params->getWidth();
  m_height = params->getHeight();

  m_textureId = params->getTextureId();
  m_currRow = 0;
  m_currFrame = 0;
}

void Node::draw()
{
  // std::cout << "Node draw :: " << m_textureId << m_x << m_y << m_width << m_height << std::endl;

  TheTextureManager::Instance()->draw(
      TheGame::Instance()->getRenderer(),
      m_textureId,
      m_x,
      m_y,
      m_width,
      m_height,
      m_currRow,
      m_currFrame);
}

void Node::update()
{
}

void Node::clean()
{
}
