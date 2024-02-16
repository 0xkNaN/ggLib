/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:26:00
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 12:27:40
 */
#pragma once

#include "Node.h"

enum class UI_STATE
{
  MOUSE_OUT = 0,
  MOUSE_HOVER = 1,
  MOUSE_CLICK = 2
};

class UI : public Node
{
public:
  UI() {}
  ~UI() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  const char *m_textureId;
  int m_currRow;
  int m_currFrame;
};
