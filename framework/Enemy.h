/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 00:31:47
 */
#pragma once

#include <iostream>

#include "Actor.h"

class Enemy : public Actor
{
public:
  Enemy() {}
  ~Enemy() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
};