/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:54:02
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:39:06
 */

#include "Enemy.h"

void Enemy::load(const LoaderParams *params)
{
  Node::load(params);
}

void Enemy::draw()
{
  Node::draw();
}

void Enemy::update()
{
  m_currFrame = int(((SDL_GetTicks() / 100) % 4));
  
  m_acceleration.setX(-0.05);
  Node::update();
}

void Enemy::clean()
{
}