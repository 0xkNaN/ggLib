/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 13:09:52
 */

#include "Player.h"

Player::Player(const LoaderParams *params) : Node(params)
{
}

// ~Player();

void Player::draw()
{
  Node::draw();
}

void Player::update()
{
  m_x += 1;
  m_currFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}