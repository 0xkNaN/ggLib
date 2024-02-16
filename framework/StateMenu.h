/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:38:28
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:18:32
 */
#pragma once

#include <vector>

#include "State.h"
#include "Node.h"

class StateMenu : public State
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual const char *getStateId() const { return s_menuId; };

  std::vector<Node *> m_gameObjects;

private:
  static const char *s_menuId;

  static void s_menuToPlay();
  static void s_exitFromMenu();
};
