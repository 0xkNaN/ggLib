/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:54:02
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 20:37:46
 */

#include "Enemy.h"

void Enemy::load(const LoaderParams *params)
{
  Actor::load(params);

  m_velocity.setX(-4);
  m_velocity.setY(-2);
}

void Enemy::update()
{
  m_currFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

  if (m_position.x() < 5)
  {
    m_velocity.setX(4);
    m_angle = 5;
    m_flip = SDL_FLIP_HORIZONTAL;
  }
  else if (m_position.x() > 507)
  {
    m_velocity.setX(-4);
    m_angle = -5;
    m_flip = SDL_FLIP_NONE;
  }

  if (m_position.y() < 5)
  {
    m_velocity.setY(2);
  }
  else if (m_position.y() > 420)
  {
    m_velocity.setY(-2);
  }

  Actor::update();
}

void Enemy::render()
{
  Actor::render();
}

void Enemy::clean()
{
}