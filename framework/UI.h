/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:26:00
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:09:55
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

  virtual void update();
  virtual void render();
  virtual void clean();

protected:
  bool m_bHovered;

  std::string m_textureId;
  int m_currRow;
  int m_currFrame;

  int m_numFrames;
  int m_animSpeed;
};
