/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 00:26:39
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 22:27:41
 */
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Object.h"
#include "Vector2D.h"

//! Do collision detection here

class Node : public Object
{
public:
  Node() {}
  ~Node() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  Vector2D position() { return m_position; }
  SDL_Rect collider() { return m_collider; }

protected:
  Vector2D m_position;

  int m_width;
  int m_height;

  SDL_Rect m_collider;
};
