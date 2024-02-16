/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 23:28:49
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 23:47:03
 */
#pragma once

#include <vector>

#include "State.h"
#include "Node.h"

class StateOver : public State
{
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual const char *stateId() const { return s_overId; };

private:
  static const char *s_overId;

  std::vector<Node *> m_gameObjects;

  static void s_onBtnOverHandler();
  static void s_onBtnRestartGame();
};
