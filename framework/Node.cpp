/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 00:42:12
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 23:11:15
 */

#include "Game.h"
#include "Node.h"

void Node::load(const LoaderParams *params)
{
  m_position = Vector2D(params->x(), params->y());
  m_width = params->width();
  m_height = params->height();
}

void Node::update()
{
  //? Collider
  m_collider.x = m_position.x();
  m_collider.y = m_position.y();
  m_collider.w = m_width;
  m_collider.h = m_height;
}

void Node::draw()
{
  SDL_SetRenderDrawColor(TheGame::Instance()->renderer(), 0, 0, 0, 1);
  SDL_RenderDrawRect(TheGame::Instance()->renderer(), &m_collider);
}

void Node::clean()
{
}