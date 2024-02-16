/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 09:58:29
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 10:13:05
 */
#pragma once

#include "Empty.h"

class Area : public Empty
{
public:
  Area(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  ~Area() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();
};
