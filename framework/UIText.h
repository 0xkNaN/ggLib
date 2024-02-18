/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 22:51:15
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:11:18
 */
#pragma once

#include "ObjectFactory.h"
#include "UI.h"

class UIText : public UI
{
public:
  UIText();
  ~UIText() {}

  virtual void load(const LoaderParams *params);

  virtual void update();
  virtual void render();
  virtual void clean();
};

class UITextCreator : public BaseCreator
{
  Node *createNode() const
  {
    return new UIText();
  }
};