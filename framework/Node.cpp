/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 00:42:12
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 00:44:58
 */

#include "Node.h"

void Node::load(const LoaderParams *params)
{
  m_position = Vector2D(params->getX(), params->getY());
}

void Node::update()
{
}

void Node::clean()
{
}