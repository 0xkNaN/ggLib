/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 23:28:49
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:09:14
 */
#pragma once

#include <vector>

#include "StateMenu.h"
#include "Node.h"

class StateMenuOver : public StateMenu
{
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string stateId() const { return s_overId; };

private:
  static std::string s_overId;

  std::vector<Node *> m_gameObjects;

  static void s_onBtnOverHandler();
  static void s_onBtnRestartGame();

  virtual void setCallbacks(const std::vector<Callback> &callbacks);
};
