/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:35:03
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 11:14:02
 */
#pragma once

class State
{
public:
  virtual ~State() {}

  virtual void update() = 0;
  virtual void render() = 0;

  virtual bool onEnter() = 0;
  virtual bool onExit() = 0;

  virtual const char *getStateId() const = 0;

protected:
  State() {}
};
