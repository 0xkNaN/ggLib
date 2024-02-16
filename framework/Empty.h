/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 09:40:26
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 11:53:57
 */
#pragma once

#include "Node.h"

class Empty : public Node
{
public:
  Empty(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  ~Empty() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
  Uint8 m_r;
  Uint8 m_g;
  Uint8 m_b;
  Uint8 m_a;
};
