/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 00:42:12
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 09:47:18
 */

#include "Node.h"

void Node::load(const LoaderParams *params)
{
  m_position = Vector2D(params->getX(), params->getY());
  m_width = params->getWidth();
  m_height = params->getHeight();
}

void Node::clean()
{
}