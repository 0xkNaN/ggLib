/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:27:01
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 12:57:57
 */
#pragma once

#include "ObjectFactory.h"
#include "UI.h"

class UIButton : public UI
{
public:
  UIButton();
  ~UIButton() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

  int callbackId() { return m_callbackId; }
  void setCallback(void (*callback)()) { m_callback = callback; }

protected:
  void (*m_callback)();
  int m_callbackId;
  bool m_bClicked;
};

class UIButtonCreator : public BaseCreator
{
  Node *createNode() const
  {
    return new UIButton();
  }
};