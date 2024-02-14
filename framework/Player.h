/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:41
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 12:39:51
 */

#pragma once

#include <iostream>

#include "Node.h"

class Player : public Node
{
public:
  Player(const LoaderParams *params);
  // ~Player();

  virtual void draw();
  virtual void update();
  virtual void clean();
};
