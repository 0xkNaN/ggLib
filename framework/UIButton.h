/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:27:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:14:16
 */
#pragma once

#include "UI.h"

class UIButton : public UI
{
public:
  UIButton(void (*callback)());
  ~UIButton() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  void (*m_callback)();

protected:
  bool m_bClicked;
};
