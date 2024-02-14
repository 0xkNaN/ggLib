/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 14:11:41
 */
#pragma once

#include <iostream>

#include "Node.h"

class Enemy : public Node
{
public:
  Enemy() {}
  ~Enemy() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();
};