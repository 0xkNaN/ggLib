/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 12:49:27
 */

#pragma once

#include <iostream>

#include "Node.h"

class Enemy : public Node
{
public:
  Enemy(const LoaderParams *params);
  // ~Player();

  virtual void draw();
  virtual void update();
  virtual void clean();
};