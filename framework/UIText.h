/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 22:51:15
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 00:00:43
 */
#pragma once

#include "UI.h"

class UIText : public UI
{
public:
  UIText();
  ~UIText() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();
};
