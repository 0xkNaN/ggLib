/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:29:58
 */

#include "Player.h"

void Player::load(const LoaderParams *params)
{
  Node::load(params);
}

void Player::draw()
{
  Node::draw();
}

void Player::update()
{
  m_currFrame = int(((SDL_GetTicks() / 100) % 5));

  // m_acceleration.setX(1);

  Node::update();
}

void Player::clean()
{
}