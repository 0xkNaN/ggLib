/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:49:56
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 00:40:42
 */
#pragma once

#include "Node.h"
#include "Vector2D.h"

class Actor : public Node
{
public:
  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  int getWidth() { return m_width; }
  int getHeight() { return m_height; }

protected:
  Actor() {}
  ~Actor() {}

  Vector2D m_velocity;
  Vector2D m_acceleration;

  int m_width;
  int m_height;

  const char *m_textureId;
  int m_currRow;
  int m_currFrame;
  double m_angle;
  SDL_RendererFlip m_flip;
};
