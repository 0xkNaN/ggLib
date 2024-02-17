/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 21:36:20
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:08:00
 */
#pragma once

#include <vector>
#include "StateMenu.h"
#include "Node.h"

class StateMenuPause : public StateMenu
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string stateId() const { return s_pauseId; };

private:
  static std::string s_pauseId;

  std::vector<Node *> m_gameObjects;

  static void s_onBtnPauseHandler();
  static void s_onBtnResumeGame();

  virtual void setCallbacks(const std::vector<Callback> &callbacks);
};
