/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:54:02
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-15 23:21:05
 */

#include "Enemy.h"

void Enemy::load(const LoaderParams *params)
{
  Actor::load(params);
}

void Enemy::draw()
{
  Actor::draw();
}

void Enemy::update()
{
  m_currFrame = int(((SDL_GetTicks() / 100) % 4));
  
  // m_acceleration.setX(-0.05);
  Actor::update();
}

void Enemy::clean()
{
}