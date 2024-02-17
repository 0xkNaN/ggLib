/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 12:05:27
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:06:56
 */
#pragma once

#include <vector>

#include "StateMenu.h"
#include "Node.h"

class StateMenuMain : public StateMenu
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string stateId() const { return s_menuId; };

private:
  static std::string s_menuId;

  std::vector<Node *> m_gameObjects;

  static void s_onBtnPlayHandler();
  static void s_onBtnExitGame();

  virtual void setCallbacks(const std::vector<Callback> &callbacks);
};