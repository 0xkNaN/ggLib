/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 21:36:20
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 21:38:59
 */
#pragma once

#include <vector>
#include "State.h"
#include "Node.h"

class StatePause : public State
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual const char *stateId() const { return s_pauseId; };

private:
  static const char *s_pauseId;

  std::vector<Node *> m_gameObjects;

  static void s_onBtnPauseHandler();
  static void s_onBtnResumeGame();
};
