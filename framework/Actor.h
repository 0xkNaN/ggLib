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

  virtual void update();
  virtual void render();
  virtual void clean();

  int width() { return m_width; }
  int height() { return m_height; }

protected:
  Actor() {}
  ~Actor() {}

  Vector2D m_velocity;
  Vector2D m_acceleration;

  std::string m_textureId;
  int m_currRow;
  int m_currFrame;
  double m_angle;
  SDL_RendererFlip m_flip;

  int m_numFrames;
};
