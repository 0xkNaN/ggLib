/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:00
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 11:15:41
 */
#pragma once

#include "State.h"

class StatePlay : public State
{
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual const char *getStateId() const { return s_playId; };

private:
  static const char *s_playId;
};