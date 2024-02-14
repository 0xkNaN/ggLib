/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:54:02
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 13:08:16
 */

#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : Node(params)
{
}

// ~Enemy();

void Enemy::draw()
{
  Node::draw();
}

void Enemy::update()
{
  m_x -= 1;
}

void Enemy::clean()
{
}