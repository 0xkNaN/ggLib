/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:38:28
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 12:10:31
 */
#pragma once

#include <vector>

#include "State.h"
#include "Node.h"

class StateMenu : public State
{
protected:
  typedef void (*Callback)();
  virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;

  std::vector<Callback> m_callbacks;
};
