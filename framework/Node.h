/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:49:56
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 12:39:39
 */
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Object.h"

class Node : public Object
{
public:
  Node(const LoaderParams *params);
  // ~Node() {}

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  int m_x;
  int m_y;
  int m_width;
  int m_height;

  const char *m_textureId;
  int m_currRow;
  int m_currFrame;
};
