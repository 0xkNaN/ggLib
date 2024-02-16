/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:48:19
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 11:21:48
 */
#pragma once

#include <iostream>
#include <vector>

#include "State.h"

class StateMachine
{

public:
  void pushState(State *state);
  void changeState(State *state);
  void popState();

  void update();
  void render();
  void clean();

private:
  std::vector<State *> m_gameStates;
};
