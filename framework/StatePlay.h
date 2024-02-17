/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:00
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:08:53
 */
#pragma once

#include <vector>

#include "State.h"
#include "Node.h"

class StatePlay : public State
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string stateId() const { return s_playId; };

private:
  static std::string s_playId;

  std::vector<Node *> m_gameObjects;

  void checkCollision();
};
