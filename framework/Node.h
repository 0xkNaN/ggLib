/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 00:26:39
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 12:28:03
 */
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Object.h"
#include "Vector2D.h"

class Node : public Object
{
public:
  virtual void load(const LoaderParams *params) = 0;

  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean();

  Vector2D getPosition() { return m_position; }

protected:
  Node() {}
  ~Node() {}

  Vector2D m_position;

  int m_width;
  int m_height;
};
