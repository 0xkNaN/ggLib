/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:49:56
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:41:51
 */
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Object.h"
#include "Vector2D.h"

class Node : public Object
{
public:
  Node() {}
  ~Node() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  int getWidth() { return m_width; }
  int getHeight() { return m_height; }
  Vector2D getPosition() { return m_position; }

protected:
  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;

  int m_width;
  int m_height;

  const char *m_textureId;
  int m_currRow;
  int m_currFrame;
  SDL_RendererFlip m_flip;
};
