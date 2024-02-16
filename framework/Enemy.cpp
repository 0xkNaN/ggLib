/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:54:02
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 23:28:01
 */

#include "Enemy.h"

void Enemy::load(const LoaderParams *params)
{
  Actor::load(params);

  m_velocity.setX(-8);
  m_velocity.setY(-4);
  m_angle = 0;
  m_flip = SDL_FLIP_NONE;
}

void Enemy::draw()
{
  Actor::draw();
}

void Enemy::update()
{
  m_currFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

  if (m_position.x() < 50)
  {
    m_velocity.setX(8);
    m_angle = 5;
    m_flip = SDL_FLIP_HORIZONTAL;
  }
  else if (m_position.x() > 850)
  {
    m_velocity.setX(-8);
    m_angle = -5;
    m_flip = SDL_FLIP_NONE;
  }

  if (m_position.y() < 20)
  {
    m_velocity.setY(4);
  }
  else if (m_position.y() > 690)
  {
    m_velocity.setY(-4);
  }

  Actor::update();
}

void Enemy::clean()
{
}