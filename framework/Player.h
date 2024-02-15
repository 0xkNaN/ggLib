/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:41
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 00:32:54
 */
#pragma once

#include <iostream>

#include "Actor.h"

class Player : public Actor
{
public:
  Player();
  ~Player() {}

  void load(const LoaderParams *params);

  void draw();
  void update();
  void clean();

private:
  void handleInputs();
};
