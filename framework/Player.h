/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:41
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-15 12:52:28
 */
#pragma once

#include <iostream>

#include "Node.h"

class Player : public Node
{
public:
  Player() : Node() {}
  ~Player() {}

  void load(const LoaderParams *params);

  void draw();
  void update();
  void clean();

private:
  void handleInputs();
};
